#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"

using namespace std;

int main() {
    srand(time(nullptr));

    int p, t;

    cout << "Enter the number of pentagons: ";
    cin >> p;
    cout << "Enter the number of hexagons: ";
    cin >> t;

    TPentagon** pentagons = createPentagons(p);
    THexagon** hexagons = createHexagons(t);

    int idxMaxPerimeter = findPentagonWithMaxPerimeter(pentagons, p);
    cout << "Pentagon with index " << idxMaxPerimeter << " with max perimeter has a perimeter of: " << pentagons[idxMaxPerimeter]->getPerimeter() << endl;
    pentagons[idxMaxPerimeter]->printPoints();

    int idxMinArea = findHexagonWithMinArea(hexagons, t);
    cout << "Hexagon with index " << idxMinArea << " with min area has an area of: " << hexagons[idxMinArea]->getArea() << endl;
    hexagons[idxMinArea]->printPoints();

    return 0;
}