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

    // Открываем файл для чтения
    ifstream inputFile("inp.txt");
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла inp.txt" << endl;
        return 1;
    }

    // Открываем файл для записи
    ofstream outputFile("../../../output.txt");
    if (!outputFile.is_open()) {
        cout << "Ошибка открытия файла output.txt" << endl;
        return 1;
    }
    streambuf* coutbuf = cout.rdbuf(); // Сохраняем старый буфер
    cout.rdbuf(outputFile.rdbuf()); // Перенаправляем cout в файл

    string line;
    while (getline(inputFile, line)) {
        if (!isValidInput(line)) {
            cout << "Данные введены некорректно: " << line << endl;
            continue; // Пропускаем некорректные строки
        }

        double a, b, c;
        istringstream iss(line);
        iss >> a >> b >> c;


        // Вывод в файл
       
        Result(a, b, c); // Выводим результат в файл

        outputFile << "-------------------" << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}