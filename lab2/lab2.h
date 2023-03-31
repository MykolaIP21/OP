#ifndef LAB2_LAB2_H
#define LAB2_LAB2_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

struct Employee {
    char name[100];
    char birthdate[11];
    char gender[20];
    char position[100];
};

void createEmployeesFile();
void createRetireesFile();
void addEmployeeToFile();
void fillRetirees();
int getCurrentYear();
int getYearOfBirth(const char* birthdate);
bool isRetired(const Employee& employee);
void printBin(const string& filename);

#endif //LAB2_LAB2_H
