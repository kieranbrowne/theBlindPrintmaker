#include "shapeDetect.h"

shapeDetect::shapeDetect(){
}
//--------------------------------
void shapeDetect::see(){
    int t = 50; // threshold
    bool isNewFrame = false;

    vidPlayer.loadMovie("inspiration/ins.mp4");
    vidPlayer.play();
    bg.loadImage("inspiration/blackBG.png");
    vidPlayer.update();
    isNewFrame = vidPlayer.isFrameNew();

    // setup cv images
    cvImg.allocate(320,320);
    greyImg.allocate(320,320);
    greyBg.allocate(320,320);
    greyDiff.allocate(320,320);

    // read from frames
    if(isNewFrame){
        cvImg.setFromPixels(vidPlayer.getPixels(),320,320);
    }
    greyImg = cvImg;
    greyBg.setFromPixels(bg.getPixels(),320,320);
    greyDiff.absDiff(greyBg,greyImg);
    greyDiff.threshold(t);
    cvImg.draw(0,0);
    contourFinder.findContours(greyDiff, 20, (320*320), 10, true); // find holes

    ofSetHexColor(0xffffff);
    ofFill();
//    contourFinder.draw(0,0);
    for (int i = 0; i < contourFinder.nBlobs; i++){
        if (shapeKnown(i)){
            addToPrints(i);
        }
    }
    
}

//--------------------------------
bool shapeDetect::shapeKnown(int blob){
    bool known = true;
    int mainPoints[10];
    int numPoints = contourFinder.blobs[blob].nPts;

    cout << "shape number " << ofToString(blob) << endl;
    cout << "number of points" << ofToString(contourFinder.blobs[blob].nPts) << endl;
    
    int size = 0;
    int next = 0;
/*    while(next != 9999){
        next = recursivePointFind(blob, -360,360,next,next);
    }*/ 

    /*ofFill();
    ofSetColor(180,180,180);
    ofBeginShape();
    int count =0;
    for (int i=0;i<numPoints;i++){
        if(abs(getAngle(blob,i,numPoints)) >= 35){
            cout << ofToString(getAngle(blob,i,numPoints)) << endl;
            ofVertex(contourFinder.blobs[blob].pts[i].x,contourFinder.blobs[blob].pts[i].y);
            mainPoints[count] = i; // find a way to append c++ arrays.
            count ++;
         }
    }
    ofEndShape(true);*/
    
   /* int co = 0;
    int x = 0; int y = 0;
    for(int i=0; i<=mainPoints.size(); i++){
       if(abs(contourFinder.blobs[blob].pts[mainPoints[i]].x -x) + abs(contourFinder.blobs[blob].pts[mainPoints[i]].y - y) >= 3){
           co++;
       }
       x = contourFinder.blobs[blob].pts[mainPoints[i]].x;
       y = contourFinder.blobs[blob].pts[mainPoints[i]].y;
    }*/

    //contourFinder.blobs[blob];
    ofSetColor(255,0,0);
    //ofDrawBitmapString(ofToString(co), contourFinder.blobs[blob].centroid);
    
    return known;
}

//--------------------------------
void shapeDetect::addToPrints(int blob){
    // read ofApp.h file
    string line;
    string pre = "";
    string post = "";
    ifstream ofapp ("../src/ofApp.h");
    bool ispre = true;
    if (ofapp.is_open()){
        while (getline (ofapp,line) ){
            if (line.find("//!!//") != string::npos){
                line.resize(line.length() -6); // remove the //!!//
                pre += line + "\n";
                ispre = false; 
            }else if (ispre){
                pre += line + "\n";
            }else if (!ispre){
                post += line + "\n";
            }
        }
        ofapp.close();
    }
    else cout << "File Not Found. Make sure it is in correct directory" << endl;
    

    int numPrints = 8; // replace with function to actually find number of prints in ofApp.cpp
    int numVerts = contourFinder.blobs[blob].nPts;
    string newPrint = "        float p";
    newPrint += ofToString((numPrints+1),4,'0');
    newPrint += "["+ofToString(numVerts)+"][2] = {";
    int lw = contourFinder.blobs[blob].boundingRect.getWidth();
    int lh = contourFinder.blobs[blob].boundingRect.getHeight();
    int lim = max(lw,lh);
    int lx = contourFinder.blobs[blob].boundingRect.getX();
    int ly = contourFinder.blobs[blob].boundingRect.getY();
    for(int i=0;i<numVerts;i++){
        float x = contourFinder.blobs[blob].pts[i].x - lx;
        float y = contourFinder.blobs[blob].pts[i].y - ly;
        // normalise
        x = ofMap(x,0,lim,0,1); 
        y = ofMap(y,0,lim,0,1); 

        newPrint += "{"+ofToString(x,3)+","+ofToString(y,3)+"}";

        if (i != numVerts-1){ newPrint += ",";}
    }  
    newPrint += "};//!!//\n";

    ofstream rewrite; 
    rewrite.open ("../src/ofApp.h");
    if (rewrite.is_open()){
        rewrite << pre;
        rewrite << newPrint;
        rewrite << post;
        rewrite.close();
    }
    else cout << "Unable to open file.";
}
/*
//--------------------------------
float shapeDetect::getAngle(int blob, int b, int tot){

    //adjacent
    int a = b-1;
    int c = b+1;

    if (a<0){
        a = tot - abs(a);
    }   
    if (c>tot){
        c = fmod(c,tot);
    }
        

    ofVec2f v1(contourFinder.blobs[blob].pts[a].x - contourFinder.blobs[blob].pts[b].x ,
           contourFinder.blobs[blob].pts[a].y - contourFinder.blobs[blob].pts[b].y);
    ofVec2f v2(contourFinder.blobs[blob].pts[b].x - contourFinder.blobs[blob].pts[c].x ,
           contourFinder.blobs[blob].pts[b].y - contourFinder.blobs[blob].pts[c].y);  
    float angle1 = v1.angle(v2);
    
    //secondary
    a = b-2;
    c = b+2;

    if (a<0)   a = tot - abs(a);
    if (c>tot) c = fmod(c,tot);

        

    ofVec2f v3(contourFinder.blobs[blob].pts[a].x - contourFinder.blobs[blob].pts[b].x ,
           contourFinder.blobs[blob].pts[a].y - contourFinder.blobs[blob].pts[b].y);
    ofVec2f v4(contourFinder.blobs[blob].pts[b].x - contourFinder.blobs[blob].pts[c].x ,
           contourFinder.blobs[blob].pts[b].y - contourFinder.blobs[blob].pts[c].y);  
    float angle2 = v3.angle(v4);
    if (abs(angle1) == 45){ // if counting by pixels    
        return angle2;
    }else{
        return angle1;
    }

}

//--------------------------------
int shapeDetect::recursivePointFind(int blob, float angle1,float angle2,int testPt, int contextPt){
    if (contextPt >= contourFinder.blobs[blob].nPts-5) {return 9999;} // if done return 9999 else return next point

    float newAngle;
    float angleMin = min(angle1,angle2);
    float angleMax = max(angle1,angle2);

    ofVec2f v1(contourFinder.blobs[blob].pts[contextPt].x - contourFinder.blobs[blob].pts[testPt].x ,
        contourFinder.blobs[blob].pts[contextPt].y - contourFinder.blobs[blob].pts[testPt].y);
    ofVec2f v2(contourFinder.blobs[blob].pts[contextPt].x - contourFinder.blobs[blob].pts[testPt].x ,
        contourFinder.blobs[blob].pts[contextPt].y - contourFinder.blobs[blob].pts[testPt].y);
            
    newAngle = v1.angle(v2);

    // tighten limiting angles?

    if ((newAngle <= angleMax) && (newAngle >= angleMin)) {
        recursivePointFind(blob, angleMin,angleMax,testPt,contextPt+1);
    }else{
        // add point to important points
        //mainPoints[0] = contextPt;
        return contextPt;
    }

}*/
