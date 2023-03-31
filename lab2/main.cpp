#include "lab2.h"

int main() {
    createEmployeesFile();
    createRetireesFile();

    fillRetirees();

    printBin("employees.bin");
    printBin("retirees.bin");

    addEmployeeToFile();
    fillRetirees();
    printBin("employees.bin");
    printBin("retirees.bin");

    return 0;
}