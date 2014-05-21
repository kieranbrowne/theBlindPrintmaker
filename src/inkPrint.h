#ifndef _INK_PRINT
#define _INK_PRINT

#include "ofMain.h"

class inkPrint{

    public:
        
        void read(float p[][2]);

        float scale;
        float x,y;
        float rot; // rotation

        inkPrint(); // constuctor
        
};

#endif
