#include "inkPrint.h"

inkPrint::inkPrint()
{
    x = 50;
    y = 50;

    rot = 0;
    scale = 100;
}
// -------------------------------
void inkPrint::read(float p[][2]){
    ofBeginShape();
    // ----------
    for(int i=0; i<=sizeof(p); i++){
        float x = p[i][0] * scale;
        float y = p[i][1] * scale;
        ofVertex(x,y);
    }
    // ----------
    ofEndShape();
}
