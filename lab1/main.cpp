#include <windows.h>
#include "stream.h"
#include "pointer.h"

using namespace std;

int main(int argc, char* argv[]) {

    SetConsoleOutputCP(CP_UTF8);

    if (!strcmp(argv[2], "FileStream")) {
        fs::cycle();
    } else if (!strcmp(argv[2], "FilePointer")) {
        fp::cycle();
    } else {
        cout << "Укажіть mode";
    }

    return 0;
}
