#include "lab2.h"

void createEmployeesFile() {
    ofstream outputFile("employees.bin", ios::binary | ios::trunc);

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++) {
        Employee employee{};
        cout << "Employee #" << i+1 << endl;
        cout << "Name: ";
        cin.ignore(); // clear input buffer
        cin.getline(employee.name, 100);
        cout << "Birthdate (DD.MM.YYYY): ";
        cin.getline(employee.birthdate, 11);
        cout << "Gender (man/woman): ";
        cin.getline(employee.gender, 20);
        cout << "Position: ";
        cin.getline(employee.position, 100);

        outputFile.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
    }

    outputFile.close();
}

void createRetireesFile() {
    ofstream outputFile("retirees.bin", ios::binary | ios::trunc);
    outputFile.close();
}

void addEmployeeToFile() {
    while (true) {
        string answer;
        cout << "Do you want to append file " << "? (y/n).";
        cin >> answer;

        if (answer == "y") {
            ofstream outputFile("employees.bin", ios::binary | ios::app);

            Employee employee;
            cout << "Adding new employee to file:" << endl;
            cout << "Name: ";
            cin.ignore(); // clear input buffer
            cin.getline(employee.name, 100);
            cout << "Birthdate (DD.MM.YYYY): ";
            cin.getline(employee.birthdate, 11);
            cout << "Gender (man/woman): ";
            cin.getline(employee.gender, 20);
            cout << "Position: ";
            cin.getline(employee.position, 100);

            char buffer[sizeof(Employee)];
            memcpy(buffer, &employee, sizeof(Employee));
            outputFile.write(buffer, sizeof(Employee));

            outputFile.close();
        } else if (answer == "n") {
            break;
        } else {
            cout << "Incorrect answer. Please, input 'y' or 'n'" << endl;
        }
    }

}

void fillRetirees() {
    ifstream inputFile("employees.bin", ios::binary);
    ofstream outputFile("retirees.bin", ios::binary);

    Employee employee;
    while (inputFile.read(reinterpret_cast<char *>(&employee), sizeof(Employee))) {
        if (isRetired(employee)) {
            outputFile.write(reinterpret_cast<const char *>(&employee), sizeof(Employee));
        }
    }

    inputFile.close();
    outputFile.close();
}

int getCurrentYear() {
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    return timePtr->tm_year + 1900;
}

int getYearOfBirth(const char* birthdate) {
    return (birthdate[6] - '0') * 1000 + (birthdate[7] - '0') * 100 + (birthdate[8] - '0') * 10 + (birthdate[9] - '0');
}

bool isRetired(const Employee& employee) {
    int currentYear = getCurrentYear();
    int birthYear = getYearOfBirth(employee.birthdate);
    cout << "Years: " << currentYear - birthYear;
    cout << " Gender: " << employee.gender << endl;
    if (strcmp(employee.gender, "man") == 0 && currentYear - birthYear >= 70) {
        return true;
    }
    if (strcmp(employee.gender, "woman") == 0 && currentYear - birthYear >= 65) {
        return true;
    }
    return false;
}

void printBin(const string& filename) {
    ifstream inputFile(filename, ios::binary);

    Employee employee{};
    cout << "Displaying contents of file " << filename << ":" << endl;
    while (inputFile.read(reinterpret_cast<char *>(&employee), sizeof(Employee))) {
        cout << "Name: " << employee.name << endl;
        cout << "Birthdate: " << employee.birthdate << endl;
        cout << "Gender: " << employee.gender << endl;
        cout << "Position: " << employee.position << endl;
        cout << endl;
    }

    inputFile.close();
}
