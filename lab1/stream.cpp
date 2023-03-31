#include "stream.h"

namespace fs {

    void cycle() {
        string filename = get_filename();

        create_file(filename);
        append_to_file(filename);

        string substring = get_substring();
        int total = 0;
        print_file(filename, "\nВхідний файл:");
        change_file(filename, substring, total);
        replace_substring(filename, total);
        print_file(filename, "\nЗмінений файл:");
        print_file("changed-" + filename, "\nВихідний файл:");
    }

    string get_filename() {
        string filename;
        cout << "Введіть ім'я файлу: ";
        cin >> filename;
        filename += ".txt";

        return filename;
    }

    void create_file(const string& filename) {
        ifstream infile(filename);
        if (infile.peek() != ifstream::traits_type::eof()) {
            cout << "Файл не пустий." << endl;
            return;
        }
        ofstream file(filename);

        file.close();

        cout << "Файл " << filename << " успішно створений\n" << endl;
    }

    void append_to_file(const string& filename) {
        while (true) {
            string answer;
            cout << "Хочете доповнити файл " << filename << "? (y/n).";
            cin >> answer;

            if (answer == "y") {
                ofstream file(filename, ios::app);

                cout << "Введіть текст для доповнення файлу:" << endl;
                string text;
                cin.ignore();
                getline(cin, text);

                file << text << endl;
                file.close();
                cout << endl;
            } else if (answer == "n") {
                break;
            } else {
                cout << "Неправильна відповідь. Будь ласка, введіть 'y' або 'n'" << endl;
            }
        }
    }

    string get_substring() {
        string substring;
        cout << "Введіть підрядок для пошуку в файлі:";
        cin.ignore();
        getline(cin, substring);

        return substring;
    }

    void print_file(const string& filename, const string& text) {
        cout << text << endl;
        ifstream file(filename);

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    void change_file(const string& filename, const string& substring, int &total) {
        ifstream infile(filename);
        ofstream outfile("temp.txt");
        string line;

        while (getline(infile, line)) {
            size_t pos = line.find(substring);
            int count = 1;
            while (pos != string::npos) {
                line.replace(pos, substring.length(), to_string(count));
                count++;
                pos = line.find(substring, pos + 1);
            }
            string end = "{" + substring + "," + to_string(count - 1) + "}";
            total += count - 1;
            outfile << line << end << endl;
        }

        infile.close();
        outfile.close();

        const char* file_name = filename.c_str();
        if (remove(file_name) != 0) {
            cerr << "Не вдалось видалити файл\n";
            return;
        }

        if (rename("temp.txt", file_name) != 0) {
            cerr << "Не вдалось перейменувати файл\n";
            return;
        }
    }

    void replace_substring(const string& filename, int total) {
        string changed_file = "changed-" + filename;

        ifstream infile(filename);
        ofstream outfile(changed_file);

        string line;

        while (getline(infile, line)) {
            outfile << line << endl;
        }

        outfile << "Загальна кількість входжень: " << total << endl;

        infile.close();
        outfile.close();
    }
}