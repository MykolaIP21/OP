#include "pointer.h"

namespace fp {

    void cycle() {
        char* filename = get_filename();

        create_file(filename);
        append_to_file(filename);

        char* substring = get_substring();
        int total = 0;
        print_file(filename, "\nВхідний файл:");
        change_file(filename, substring, total);
        replace_substring(filename, substring, total);
        print_file(filename, "\nЗмінений файл:");

        char* changed_filename = new char[strlen(filename) + 9];
        strcpy(changed_filename, "changed-");
        strcat(changed_filename, filename);

        print_file(changed_filename, "\n\nВихідний файл:");

        delete[] filename;
        delete[] substring;
        delete[] changed_filename;
    }

    char* get_filename() {
        char filename[256];
        cout << "Введіть ім'я файлу: ";
        cin >> filename;
        strcat(filename, ".txt");

        char* result = new char[strlen(filename) + 1];
        strcpy(result, filename);

        return result;
    }

    void create_file(char* filename) {
        FILE* file = fopen(filename, "r");
        if (file != nullptr) {
            fseek(file, 0, SEEK_END);
            if (ftell(file) != 0) {
                cout << "Файл не пустий" << endl;
                fclose(file);
                return;
            }
            fclose(file);
        }

        file = fopen(filename, "w");
        if (file == nullptr) {
            cout << "Не вдалось створити файл " << filename << endl;
            return;
        }

        fclose(file);
        cout << "Файл " << filename << " успішно створений\n" << endl;
    }

    void append_to_file(char* filename) {
        while (true) {
            char answer;
            cout << "Хочете доповнити файл " << filename << "? (y/n).";
            cin >> answer;

            if (answer == 'y') {
                FILE* file = fopen(filename, "a");
                if (file == nullptr) {
                    cout << "Не вдалось відкрити файл " << filename << endl;
                    continue;
                }

                cout << "Введіть текст для доповнення файлу:" << endl;
                char text[1024];
                cin.ignore();
                cin.getline(text, sizeof(text));
                if (cin.fail()) {
                    cerr << "Помилка вводу даних" << endl;
                    fclose(file);
                    continue;
                }
                fputs(text, file);
                fputc('\n', file);
                fclose(file);
                cout << "\n";
            } else if (answer == 'n') {
                break;
            } else {
                cout << "Неправильна відповідь. Будь ласка, введіть 'y' або 'n'" << endl;
            }
        }
    }

    char* get_substring() {
        char substring[256];
        cout << "Введіть підрядок для пошуку в файлі:";
        cin.ignore();
        cin.getline(substring, sizeof(substring));
        char* result = new char[strlen(substring) + 1];
        strcpy(result, substring);

        return result;
    }

    void print_file(char* filename, const char* text) {
        cout << text << endl;
        FILE* file = fopen(filename, "r");
        if (file == nullptr) {
            cerr << "Не вдалось відкрити файл " << filename << endl;
            return;
        }

        char line[1024];
        while (fgets(line, sizeof(line), file) != nullptr) {
            cout << line;
        }

        fclose(file);
    }

    void change_file(char* filename, char* substring, int& total) {
        FILE *infile = fopen(filename, "r");
        const size_t max_lines = 1024;
        char **lines = new char*[max_lines];
        size_t line_count = 0;

        char buffer[256];
        while (fgets(buffer, sizeof(buffer), infile) && line_count < max_lines) {
            lines[line_count] = new char[strlen(buffer) + 1];
            strcpy(lines[line_count], buffer);
            line_count++;
        }

        fclose(infile);

        FILE *outfile = fopen(filename, "w");

        bool first_line = true;
        for (size_t i = 0; i < line_count; i++) {
            if (!first_line) {
                fwrite("\n", 1, 1, outfile);
            } else {
                first_line = false;
            }

            int line_total = 0;
            const char *pos = lines[i];
            const char *cur = lines[i];
            while ((pos = strstr(cur, substring)) != nullptr) {
                fwrite(cur, 1, pos - cur, outfile);
                char temp[256];
                snprintf(temp, sizeof(temp), "%d", line_total + 1);
                fwrite(temp, 1, strlen(temp), outfile);

                pos += strlen(substring);
                cur = pos;
                total++;
                line_total++;
            }
            fwrite(cur, 1, strlen(cur) - 1, outfile);

            // Вставити {} в кінець рядка
            snprintf(buffer, sizeof(buffer), "{%s,%d}", substring, line_total);
            fwrite(buffer, 1, strlen(buffer), outfile);
        }

        fclose(outfile);

        // Звілнення пам'яті
        for (size_t i = 0; i < line_count; i++) {
            delete[] lines[i];
        }
        delete[] lines;
    }

    void replace_substring(char* filename, char* substring, int total) {
        char* changed_file = new char[strlen(filename) + 9];
        strcpy(changed_file, "changed-");
        strcat(changed_file, filename);
        FILE* infile = fopen(filename, "r");
        FILE* outfile = fopen(changed_file, "w");

        char line[1024];

        while (fgets(line, sizeof(line), infile) != nullptr) {
            fputs(line, outfile);
        }

        fprintf(outfile, "\nЗагальна кількість входжень: %d\n", total);

        fclose(infile);
        fclose(outfile);

        delete[] changed_file;
    }
}
