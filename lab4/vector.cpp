#include "vector.h"
#include <cstdlib>


Vector::Vector() : length(0), angle(0) {}
Vector::Vector(double length, double angle) : length(length), angle(angle) {}

double Vector::get_length() const {
    return length;
}

double Vector::get_angle() const {
    return angle;
}

void Vector::rotate(double rotation_angle) {
    angle += rotation_angle;
}

Vector Vector::operator+(const Vector& other) const {
    double x = length * cos(angle) + other.length * cos(other.angle);
    double y = length * sin(angle) + other.length * sin(other.angle);
    double new_length = sqrt(x * x + y * y);
    double new_angle = atan2(y, x);
    return {new_length, new_angle};
}

Vector Vector::operator/(double divisor) const {
    if (divisor == 0) {
        cerr << "Не можна ділити на нуль!\n";
        exit(EXIT_FAILURE);
    }
    return {length / divisor, angle};
}
