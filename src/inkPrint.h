#ifndef _INK_PRINT
#define _INK_PRINT

#include "ofMain.h"

class inkPrint{

    public:
        
        void read(float p[][2],float dx,float dy,float scale,float rot);

        float scale;
        float dx,dy;
        float rot; // rotation

        inkPrint(); // constuctor
        
};

#endif
