#include "CPP_1.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool isValidInput(const string& line) {
    istringstream iss(line);
    double a, b, c;
    char extra;
    return (iss >> a >> b >> c) && !(iss >> extra);
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    // ��������� ���� ��� ������
    ifstream inputFile("inp.txt");
    if (!inputFile.is_open()) {
        cout << "������ �������� ����� inp.txt" << endl;
        return 1;
    }

    // ��������� ���� ��� ������
    ofstream outputFile("../../../output.txt");
    if (!outputFile.is_open()) {
        cout << "������ �������� ����� output.txt" << endl;
        return 1;
    }
    streambuf* coutbuf = cout.rdbuf(); // ��������� ������ �����
    cout.rdbuf(outputFile.rdbuf()); // �������������� cout � ����

    string line;
    while (getline(inputFile, line)) {
        if (!isValidInput(line)) {
            cout << "������ ������� �����������: " << line << endl;
            continue; // ���������� ������������ ������
        }

        double a, b, c;
        istringstream iss(line);
        iss >> a >> b >> c;


        // ����� � ����
       
        Result(a, b, c); // ������� ��������� � ����

        outputFile << "-------------------" << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}