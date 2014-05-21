#include "inkPrint.h"

inkPrint::inkPrint()
{
    dx = 50;
    dy = 50;

    rot = 0;
    scale = 100;
}

// -------------------------------
void inkPrint::read(float p[][2],float dx,float dy,float scale,float rot){
    ofBeginShape();
    // ----------
    for(int i=0; i<=sizeof(p); i++){
        float x = dx + (p[i][0] * scale);
        float y = dy + (p[i][1] * scale);
        ofVertex(x,y);
    }
    // ----------
    ofEndShape();
}
