#ifndef _SHAPE_DETECT
#define _SHAPE_DETECT

#include "ofMain.h"

#include "ofxOpenCv.h"

class shapeDetect
{

    public:
        
        void see();
        bool shapeKnown(int blob);
        void addToPrints(int blob);
        float getAngle(int blob, int b, int tot);
        int recursivePointFind(int blob, float angle1,float angle2,int testPt, int contextPt);
        

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
