#pragma once

#include "ofMain.h"

//file logging
#include <iostream>
#include <fstream>
using namespace std;

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
};
