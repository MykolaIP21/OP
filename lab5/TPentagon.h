#ifndef TEST_TPENTAGON_H
#define TEST_TPENTAGON_H


#include "TFigure.h"
#include "Point.h"

class TPentagon : public TFigure {
private:
    Point points[5]{};
public:
    explicit TPentagon(Point* pts);
    double getArea() override;
    double getPerimeter() override;
    void printPoints();
};


#endif //TEST_TPENTAGON_H
