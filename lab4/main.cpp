#include "vector.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Vector V1, V2(4, M_PI / 4), V3(2, M_PI / 2);

    cout << "Початкові значення векторів:" << endl;
    cout << "V1: (" << V1.get_length() << ", " << V1.get_angle() << ")\n";
    cout << "V2: (" << V2.get_length() << ", " << V2.get_angle() << ")\n";
    cout << "V3: (" << V3.get_length() << ", " << V3.get_angle() << ")\n";

    V3.rotate(M_PI / 4);
    V2 = V2 / 2;

    cout << "Проміжні значення векторів:" << endl;
    cout << "V2: (" << V2.get_length() << ", " << V2.get_angle() << ")\n";
    cout << "V3: (" << V3.get_length() << ", " << V3.get_angle() << ")\n";

    V1 = V2 + V3;

    cout << "Кінцеві значення векторів:" << endl;
    cout << "V1: (" << V1.get_length() << ", " << V1.get_angle() << ")\n";
    cout << "V2: (" << V2.get_length() << ", " << V2.get_angle() << ")\n";
    cout << "V3: (" << V3.get_length() << ", " << V3.get_angle() << ")\n";

    return 0;
}
