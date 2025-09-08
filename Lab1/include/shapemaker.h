#ifndef SHAPEMAKER_H
#define SHAPEMAKER_H

#include <string>
using namespace std;

class ShapeMaker {
private:
    int canvasWidth;
    int canvasHeight;
    char symbol;

public:
    // Constructors
    ShapeMaker();
    ShapeMaker(int width, int height, char sym);

    // Getters
    int getCanvasWidth() const;
    int getCanvasHeight() const;
    char getSymbol() const;

    // Setters
    void setCanvasWidth(int width);
    void setCanvasHeight(int height);
    void setSymbol(char sym);

    // Drawing functions
    void drawHorizontalLine() const;
    void drawVerticalLine() const;
    void drawFilledSquare() const;
    void drawOpenSquare() const;
    void drawSmileyFace() const;
    void drawCircle() const; // Bonus
};

#endif