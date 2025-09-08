#include "shapemaker.h"
#include <iostream>
using namespace std;

int main() {
    ShapeMaker sm;
    sm.drawHorizontalLine();
    sm.drawVerticalLine();
    sm.drawFilledSquare();
    sm.drawOpenSquare();
    sm.drawSmileyFace();
    sm.drawCircle();
    return 0;
}