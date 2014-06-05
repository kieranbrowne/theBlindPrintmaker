#pragma once

#include "ofMain.h"

//file logging
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <sys/stat.h>

#include "inkPrint.h"
#include "shapeDetect.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void canvas(int alpha);
        void log();
        int logLength();
        inline bool fileExists (const string& name);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        

        // global vars
        ofImage img;
        int count;
        string fileName;
        int w,h;

        // shape detect class
        shapeDetect inspiration;

        // print class
        inkPrint print;
        float p0000[4][2] = {{0,0},{0,0},{1,1},{0,1}};
        float p0001[5][2] = {{0,0},{1,0},{1,1},{0,1},{1,1}};//!!//

};
