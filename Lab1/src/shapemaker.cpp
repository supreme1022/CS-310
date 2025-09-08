#include "shapemaker.h"
#include <iostream>
using namespace std;

ShapeMaker::ShapeMaker() : canvasWidth(21), canvasHeight(21), symbol('*') {}
ShapeMaker::ShapeMaker(int width, int height, char sym)
    : canvasWidth(width), canvasHeight(height), symbol(sym) {}

int ShapeMaker::getCanvasWidth() const { return canvasWidth; }
int ShapeMaker::getCanvasHeight() const { return canvasHeight; }
char ShapeMaker::getSymbol() const { return symbol; }

void ShapeMaker::setCanvasWidth(int width) { canvasWidth = width; }
void ShapeMaker::setCanvasHeight(int height) { canvasHeight = height; }
void ShapeMaker::setSymbol(char sym) { symbol = sym; }

void ShapeMaker::drawHorizontalLine() const {
    for (int i = 0; i < canvasWidth; i++) cout << symbol;
    cout << endl;
}

void ShapeMaker::drawVerticalLine() const {
    for (int i = 0; i < canvasHeight; i++) {
        cout << symbol << endl;
    }
}

void ShapeMaker::drawFilledSquare() const {
    for (int i = 0; i < canvasWidth; i++) {
        for (int j = 0; j < canvasWidth; j++) cout << symbol;
        cout << endl;
    }
}

void ShapeMaker::drawOpenSquare() const {
    for (int i = 0; i < canvasWidth; i++) {
        for (int j = 0; j < canvasWidth; j++) {
            if (i == 0 || i == canvasWidth - 1 || j == 0 || j == canvasWidth - 1)
                cout << symbol;
            else
                cout << " ";
        }
        cout << endl;
    }
}

void ShapeMaker::drawSmileyFace() const {
    cout << "Smiley face drawing not yet implemented!" << endl;
}

void ShapeMaker::drawCircle() const {
    cout << "Circle drawing not yet implemented!" << endl;
}