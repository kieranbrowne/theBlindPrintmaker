#include "shapeDetect.h"

shapeDetect::shapeDetect(){
}
//--------------------------------
void shapeDetect::see(){
    int t = 20; // threshold
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
//    greyDiff.draw(0,0);
    contourFinder.findContours(greyDiff, 20, (320*320), 10, true); // find holes

    ofSetHexColor(0xffffff);
    ofFill();
//    contourFinder.draw(0,0);
    for (int i = 0; i < contourFinder.nBlobs; i++){
        contourFinder.blobs[i].draw(0,0);
        ofDrawBitmapString(ofToString(i), contourFinder.blobs[i].centroid);
        cout << ofToString(contourFinder.blobs[i].nPts) << endl;
    }
    
}

//--------------------------------
bool shapeDetect::shapeKnown(int blobNum){
    bool known = false;

    
    return known;
}
//--------------------------------
void shapeDetect::addToPrints(int blobNum){
    
}
