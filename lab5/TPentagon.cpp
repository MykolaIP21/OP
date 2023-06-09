#include "TPentagon.h"
#include "functions.h"
#include <cmath>
#include <iostream>

using namespace std;


TPentagon::TPentagon(Point* pts) {
    for (int i = 0; i < 5; i++) {
        points[i] = pts[i];
    }
}

double TPentagon::getArea() {
    double area = 0;
    for (int i = 0; i < 5; i++) {
        area += (points[i].x * points[(i + 1) % 5].y) - (points[(i + 1) % 5].x * points[i].y);
    }
    return abs(area) / 2.0;
}

double TPentagon::getPerimeter() {
    double perimeter = 0;
    for (int i = 0; i < 5; i++) {
        perimeter += dist(points[i], points[(i + 1) % 5]);
    }
    return perimeter;
}

void TPentagon::printPoints() {
    for (const auto &point : points) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }
}
