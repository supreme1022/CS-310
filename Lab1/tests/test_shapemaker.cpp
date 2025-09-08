#include "shapemaker.h"
#include <cassert>

int main() {
    ShapeMaker sm(10, 10, '#');
    assert(sm.getCanvasWidth() == 10);
    assert(sm.getCanvasHeight() == 10);
    assert(sm.getSymbol() == '#');
    return 0;
}