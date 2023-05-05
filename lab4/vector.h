#ifndef LAB4_VECTOR_H
#define LAB4_VECTOR_H
#include <cmath>
#include <iostream>
using namespace std;


class Vector {
private:
    double length;
    double angle;

public:
    Vector();
    Vector(double length, double angle);

    [[nodiscard]] double get_length() const;
    [[nodiscard]] double get_angle() const;

    void rotate(double rotation_angle);

    Vector operator+(const Vector& other) const;
    Vector operator/(double divisor) const;
};


#endif
