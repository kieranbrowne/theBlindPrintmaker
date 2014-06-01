#ifndef _SHAPE_DETECT
#define _SHAPE_DETECT

#include "ofMain.h"

#include "ofxOpenCv.h"

class shapeDetect{

    public:
        
        void see();

        ofxCvColorImage         cvImg;
        ofxCvGrayscaleImage     greyImg;
        ofxCvGrayscaleImage     greyBg;
        ofxCvGrayscaleImage     greyDiff;
        ofxCvContourFinder      contourFinder;

        ofImage ins;
        ofImage bg;
        ofPixels insp;
        ofVideoPlayer vidPlayer;
        

        shapeDetect(); // constuctor
        
};

#endif
