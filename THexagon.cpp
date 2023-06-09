#include "THexagon.h"
#include "functions.h"
#include <cmath>
#include <iostream>

using namespace std;

THexagon::THexagon(Point* pts) {
    for (int i = 0; i < 6; i++) {
        points[i] = pts[i];
    }
}

double THexagon::getArea() {
    double area = 0;
    for (int i = 0; i < 6; i++) {
        area += (points[i].x * points[(i + 1) % 6].y) - (points[(i + 1) % 6].x * points[i].y);
    }
    return abs(area) / 2.0;
}

double THexagon::getPerimeter() {
    double perimeter = 0;
    for (int i = 0; i < 6; i++) {
        perimeter += dist(points[i], points[(i + 1) % 6]);
    }
    return perimeter;
}

void THexagon::printPoints() {
    for (const auto &point : points) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }
}
