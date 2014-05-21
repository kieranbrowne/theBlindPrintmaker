#include "inkPrint.h"

inkPrint::inkPrint()
{
    x = 50;
    y = 50;

    rot = 0;
    scale = 100;
}
// -------------------------------
void inkPrint::p0000(){
    ofSetColor(12,40,53,80);
    ofBeginShape();
    ofVertex(x,y);
    ofVertex(x+scale,y);
    ofVertex(x+scale,y+scale);
    ofVertex(x,y+scale);
    ofEndShape();
}
