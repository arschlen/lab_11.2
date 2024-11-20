#include <iostream>
#include <fstream>
#include <cctype> // ��� ������� isalpha, isdigit, tolower
#include <string>
using namespace std;

// ������� ��� ��������� �����
void CreateTXT(const char* fname) {
    ofstream fout(fname); // �������� ����� ��� ������
    char ch;
    string s;
    do {
        cin.ignore(); // �������� ������ �����
        cout << "Enter line: ";
        getline(cin, s);
        fout << s << endl; // ����� ����� � ����
        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

// ������� ��� ��������� ����� �����
void PrintTXT(const char* fname) {
    ifstream fin(fname); // �������� ����� ��� �������
    string s;
    while (getline(fin, s)) {
        cout << s << endl;
    }
    cout << endl;
}

// ������� ��� ������� �����
void ProcessFile(const char* inputFile, const char* outputFile) {
    ifstream fin(inputFile);   // �������� ����� ��� �������
    ofstream fout(outputFile); // �������� ����� ��� ������

    string line; // ��� ������� ����� � �����
    bool foundFirstSpace = false;

    while (getline(fin, line)) { // ������ ���� ����� �� ������
        string result = "";      // ����� ��� ������ � outputFile
        for (char c : line) {
            if (c == ' ') { // ���� ������� ������ �����
                foundFirstSpace = true;
                break; // �������� � ������� ��������� �����
            }
            if (isalnum(c)) { // �������� ����� ����� �� �����
                result += isalpha(c) ? tolower(c) : c; // ����� ����� �������� �� �������
            }
        }

        if (!result.empty()) { // ���� � ���� ��� ������
            fout << result << endl;
        }

        if (foundFirstSpace) { // ���� ����� ��� ��������, ���������� �������
            break;
        }
    }
}

int main() {
    char t1[100], t2[100];
    cout << "Enter input file name (t1): ";
    cin >> t1;
    CreateTXT(t1); // ��������� �������� �����

    cout << "File content (t1):" << endl;
    PrintTXT(t1); // ��������� ����� �������� �����

    cout << "Enter output file name (t2): ";
    cin >> t2;

    ProcessFile(t1, t2); // ������� ����� t1 � ����� � t2

    cout << "Processed file content (t2):" << endl;
    PrintTXT(t2); // ��������� ����� ��������� �����

    return 0;
}
