#pragma once

#include "ofMain.h"

//file logging
#include <iostream>
#include <fstream>
using namespace std;

#include "inkPrint.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void canvas(int alpha);
        void log();

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

        // print class
        inkPrint print;
        float p0000[4][2] = {{0,0},{0,0},{1,1},{0,1}};
        float p0001[4][2] = {{0,0},{1,0},{1,1},{0,1}};

};
