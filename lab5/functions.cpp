#include "functions.h"
#include <cmath>
#include <cstdlib>

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point* generatePoints(int n, double radius, Point center) {
    Point* points = new Point[n];
    double slice = 2 * M_PI / n;
    for (int i = 0; i < n; i++) {
        double angle = slice * i;
        points[i] = {center.x + radius * cos(angle), center.y + radius * sin(angle)};
    }
    return points;
}

TPentagon** createPentagons(int count) {
    auto** pentagons = new TPentagon*[count];
    for (int i = 0; i < count; i++) {
        Point center = {double(rand() % 100), double(rand() % 100)};
        auto radius = double(rand() % 100 + 1);
        Point* pts = generatePoints(5, radius, center);
        pentagons[i] = new TPentagon(pts);
        delete[] pts;
    }
    return pentagons;
}

THexagon** createHexagons(int count) {
    auto** hexagons = new THexagon*[count];
    for (int i = 0; i < count; i++) {
        Point center = {double(rand() % 100), double(rand() % 100)};
        auto radius = double(rand() % 100 + 1);
        Point* pts = generatePoints(6, radius, center);
        hexagons[i] = new THexagon(pts);
        delete[] pts;
    }
    return hexagons;
}

int findPentagonWithMaxPerimeter(TPentagon** pentagons, int count) {
    int idxMaxPerimeter = 0;
    for (int i = 1; i < count; i++) {
        if (pentagons[i]->getPerimeter() > pentagons[idxMaxPerimeter]->getPerimeter()) {
            idxMaxPerimeter = i;
        }
    }
    return idxMaxPerimeter;
}

int findHexagonWithMinArea(THexagon** hexagons, int count) {
    int idxMinArea = 0;
    for (int i = 1; i < count; i++) {
        if (hexagons[i]->getArea() < hexagons[idxMinArea]->getArea()) {
            idxMinArea = i;
        }
    }
    return idxMinArea;
}
