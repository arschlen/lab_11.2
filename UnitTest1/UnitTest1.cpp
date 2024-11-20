#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// Ваші функції без заголовкових файлів
void CreateTXT(const char* fname) {
    ofstream fout(fname);
    char ch;
    string s;
    do {
        s = "Hello world";  // фіктивний введений рядок
        fout << s << endl;
        ch = 'n';  // фіктивний вибір користувача
    } while (ch == 'y' || ch == 'Y');
}

void PrintTXT(const char* fname) {
    ifstream fin(fname);
    string s;
    while (getline(fin, s)) {
        cout << s << endl;
    }
}

void ProcessFile(const char* inputFile, const char* outputFile) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    string line;
    bool foundFirstSpace = false;

    while (getline(fin, line)) {
        string result = "";
        for (char c : line) {
            if (c == ' ') {
                foundFirstSpace = true;
                break;
            }
            if (isalnum(c)) {
                result += isalpha(c) ? tolower(c) : c;
            }
        }

        if (!result.empty()) {
            fout << result << endl;
        }

        if (foundFirstSpace) {
            break;
        }
    }
}

// Ось ваші юніт-тести
namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCreateTXT)
        {
            // Тестуємо функцію CreateTXT
            const char* testFile = "test_create.txt";
            CreateTXT(testFile);

            // Перевірка, чи був створений файл
            ifstream fin(testFile);
            Assert::IsTrue(fin.is_open(), L"File not created successfully.");
            fin.close();
        }
    };
}
