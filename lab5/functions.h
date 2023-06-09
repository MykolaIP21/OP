#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include "Point.h"
#include "TPentagon.h"
#include "THexagon.h"

double dist(const Point& a, const Point& b);
Point* generatePoints(int n, double radius, Point center);
TPentagon** createPentagons(int count);
THexagon** createHexagons(int count);
int findPentagonWithMaxPerimeter(TPentagon** pentagons, int count);
int findHexagonWithMinArea(THexagon** hexagons, int count);


#endif //TEST_FUNCTIONS_H
