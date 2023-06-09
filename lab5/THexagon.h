#ifndef TEST_THEXAGON_H
#define TEST_THEXAGON_H


#include "TFigure.h"
#include "Point.h"

class THexagon : public TFigure {
private:
    Point points[6]{};
public:
    explicit THexagon(Point* pts);
    double getArea() override;
    double getPerimeter() override;
    void printPoints();
};


#endif //TEST_THEXAGON_H
