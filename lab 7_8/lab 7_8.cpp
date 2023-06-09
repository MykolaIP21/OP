#include <windows.h>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>

using namespace std;

const int BUF_SIZE = 20;
const int START_ID = 2, END_ID = 4, STEP_ID = 6, RESULT_ID = 8;

class InvTrigFunc {
    double x;
public:
    explicit InvTrigFunc(double val) : x(val) {}

    [[nodiscard]] double calc() const {
        if (x < -1 || x > 1) {
            throw invalid_argument("Invalid value of x, should be between -1 and 1.");
        }
        return atan(sqrt(3) * x);
    }
};

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    static HWND hwndStart, hwndEnd, hwndStep, hwndResult;
    switch (msg) {
        case WM_CREATE:
            CreateWindow("Static", "Start:", WS_CHILD | WS_VISIBLE,
                         50, 50, 100, 25, hwnd, (HMENU)1, nullptr, nullptr);
            hwndStart = CreateWindow("Edit", nullptr, WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     150, 50, 100, 25, hwnd, (HMENU)START_ID, nullptr, nullptr);

            CreateWindow("Static", "End:", WS_CHILD | WS_VISIBLE,
                         50, 100, 100, 25, hwnd, (HMENU)3, nullptr, nullptr);
            hwndEnd = CreateWindow("Edit", nullptr, WS_CHILD | WS_VISIBLE | WS_BORDER,
                                   150, 100, 100, 25, hwnd, (HMENU)END_ID, nullptr, nullptr);

            CreateWindow("Static", "Step:", WS_CHILD | WS_VISIBLE,
                         50, 150, 100, 25, hwnd, (HMENU)5, nullptr, nullptr);
            hwndStep = CreateWindow("Edit", nullptr, WS_CHILD | WS_VISIBLE | WS_BORDER,
                                    150, 150, 100, 25, hwnd, (HMENU)STEP_ID, nullptr, nullptr);

            CreateWindow("Button", "Calculate", WS_CHILD | WS_VISIBLE,
                         50, 200, 75, 25, hwnd, (HMENU)7, nullptr, nullptr);
            hwndResult = CreateWindow("Edit", nullptr, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
                                      50, 250, 400, 200, hwnd, (HMENU)RESULT_ID, nullptr, nullptr);
            break;
        case WM_COMMAND:
            if (LOWORD(wparam) == 7) {
                char bufStart[BUF_SIZE], bufEnd[BUF_SIZE], bufStep[BUF_SIZE];
                GetWindowText(hwndStart, bufStart, BUF_SIZE);
                GetWindowText(hwndEnd, bufEnd, BUF_SIZE);
                GetWindowText(hwndStep, bufStep, BUF_SIZE);

                try {
                    double start = stod(bufStart);
                    double end = stod(bufEnd);
                    double step = stod(bufStep);

                    if(step == 0) {
                        throw invalid_argument("Step cannot be zero.");
                    }

                    if(start > end) {
                        throw invalid_argument("Start value is greater than end value.");
                    }

                    string result;
                    for (double x = start; x <= end; x += step) {
                        try {
                            InvTrigFunc func(x);
                            stringstream ss;
                            ss << "The value of arctg(sqrt(3)*" << x << ") = " << func.calc() << "\r\n";
                            result += ss.str();
                        } catch (invalid_argument& e) {
                            result += string("Error: ") + e.what() + "\r\n";
                        }
                    }
                    SetWindowText(hwndResult, result.c_str());
                } catch(invalid_argument& e) {
                    SetWindowText(hwndResult, (string("Input error: ") + e.what()).c_str());
                }
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wparam, lparam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow) {
    const char CLASS_NAME[] = "Sample Window Class";
    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "Lab7_8",
                               WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                               nullptr, nullptr, hInst, nullptr);

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
