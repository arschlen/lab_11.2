#include <iostream>
#include <fstream>
#include <cctype> // Для функцій isalpha, isdigit, tolower
#include <string>
using namespace std;

// Функція для створення файлу
void CreateTXT(const char* fname) {
    ofstream fout(fname); // відкриття файлу для запису
    char ch;
    string s;
    do {
        cin.ignore(); // очищення буфера вводу
        cout << "Enter line: ";
        getline(cin, s);
        fout << s << endl; // запис рядка у файл
        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

// Функція для виведення вмісту файлу
void PrintTXT(const char* fname) {
    ifstream fin(fname); // відкриття файлу для читання
    string s;
    while (getline(fin, s)) {
        cout << s << endl;
    }
    cout << endl;
}

// Функція для обробки файлу
void ProcessFile(const char* inputFile, const char* outputFile) {
    ifstream fin(inputFile);   // відкриття файлу для читання
    ofstream fout(outputFile); // відкриття файлу для запису

    string line; // для читання рядків з файлу
    bool foundFirstSpace = false;

    while (getline(fin, line)) { // читаємо файл рядок за рядком
        string result = "";      // рядок для запису в outputFile
        for (char c : line) {
            if (c == ' ') { // якщо знайшли перший пробіл
                foundFirstSpace = true;
                break; // виходимо з обробки поточного рядка
            }
            if (isalnum(c)) { // залишаємо тільки літери та цифри
                result += isalpha(c) ? tolower(c) : c; // великі букви замінюємо на маленькі
            }
        }

        if (!result.empty()) { // якщо є щось для запису
            fout << result << endl;
        }

        if (foundFirstSpace) { // якщо пробіл уже знайдено, припиняємо обробку
            break;
        }
    }
}

int main() {
    char t1[100], t2[100];
    cout << "Enter input file name (t1): ";
    cin >> t1;
    CreateTXT(t1); // створення вхідного файлу

    cout << "File content (t1):" << endl;
    PrintTXT(t1); // виведення вмісту вхідного файлу

    cout << "Enter output file name (t2): ";
    cin >> t2;

    ProcessFile(t1, t2); // обробка файлу t1 і запис у t2

    cout << "Processed file content (t2):" << endl;
    PrintTXT(t2); // виведення вмісту вихідного файлу

    return 0;
}
