#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    count = logLength();
    fileName = ofToString(count,5,'0') + ".png"; 
    log();
    w = ofGetWindowWidth();
    h = ofGetWindowHeight();

    if(fileExists("data/inspiration/ins.mp4")) inspiration.see();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetFrameNum() >= 1){
        ofSleepMillis(4000);
        ofExit();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    // bg texture
    ofBackground(ofColor::fromHsb(30, 20, 230));
    canvas(80);

//////////////////////////////////////////////
    ofPushMatrix();
    //!s!// 
    print.colour(180,200,200,100);
    print.read(p0000,100,100,200,0);
    print.read(p0001,100,100,200,0);
    //!e!//
    ofPopMatrix();
//////////////////////////////////////////////


    img.grabScreen(0,0,w,h);
    img.saveImage(fileName);

}

//--------------------------------------------------------------
void ofApp::canvas(int alpha){
    for(int i = 0; i<w; i+=2){
        for(int j=0; j<h; j+=2){
            int f = floor(ofRandom(220,250));
            ofSetColor(f,f,f,alpha);
            ofRect(i,j,2,2);
        }
    }
    for(int i = 0; i<18; i++){
        int f = floor(ofRandom(160,210));
        ofSetColor(f,f,f,ofRandom(alpha*1.6,alpha*2.6));
        ofRect(ofRandom(0,w),ofRandom(0,h),ofRandom(1,3),ofRandom(1,3));
    }
}

//--------------------------------------------------------------
void ofApp::log(){
  ofstream logfile ("log.csv",ios::out | ios::app);
  if (logfile.is_open())
  {
    logfile << fileName << ",";
    logfile << ofToString(count) << "\n";
    logfile.close();
  }
  else cout << "Unable to open file";
}
//--------------------------------------------------------------
int ofApp::logLength(){
    int numLines = 0;
    string line;
    ifstream logFile("log.csv");

    while (getline(logFile, line))
        ++numLines;
    return numLines;
}

//--------------------------------------------------------------
inline bool ofApp::fileExists (const string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
