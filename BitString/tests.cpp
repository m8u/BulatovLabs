#include <Testing/Testing.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <BitString/BitString.hpp>

using namespace Testing;
using namespace std;

int main() {
    int testNumber = 1;

    // Операторы ввода-вывода для stdin/stdout и текстовых файловых потоков
    BitString bitString1, bitString2;
    //bitString1 = BitString("1234567890ABCDEF");
    //bitString2 = BitString("12F4A9969BAB7C0A");
    istringstream iss("1234567890ABCDEF");
    ostringstream oss;
    iss >> bitString1;
    oss << bitString1;
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), "1234567890ABCDEF") << '\n';
    testNumber++;
    iss.clear();
    oss.str("");
    oss.clear();

    iss.str("12F4A9969BAB7C0A");
    iss >> bitString2;
    oss << bitString2;
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), "12F4A9969BAB7C0A") << '\n' << '\n';
    testNumber++;
    iss.clear();
    oss.str("");
    oss.clear();

    ofstream outFileTxt ("bitstrings.txt");
    if (outFileTxt) {
        outFileTxt << bitString1;
        outFileTxt << bitString2;
        outFileTxt.close();
    }

    ifstream inFileTxt ("bitstrings.txt");
    if (inFileTxt) {
        inFileTxt >> bitString1;
        inFileTxt >> bitString2;
        inFileTxt.close();
    }

    cout << testNumber << ": " << testMsg((char*)bitString1, "1234567890ABCDEF") << '\n';
    testNumber++;
    cout << testNumber << ": " << testMsg((char*)bitString2, "12F4A9969BAB7C0A") << '\n' << '\n';
    testNumber++;

    // Запись и чтение бинарных файлов
    ofstream outFileBin ("bitstrings.dat");
    if (outFileBin) {
        outFileBin.write((char*)&bitString1, sizeof(BitString));
        outFileBin.seekp(sizeof(BitString), ios::beg);
        outFileBin.write((char*)&bitString2, sizeof(BitString));
        outFileBin.close();
    }

    ifstream inFileBin ("bitstrings.dat");
    if (inFileBin) {
        inFileBin.read((char*)&bitString1, sizeof(BitString));
        inFileBin.seekg(sizeof(BitString), ios::beg);
        inFileBin.read((char*)&bitString2, sizeof(BitString));
        inFileBin.close();
    }

    cout << testNumber << ": " << testMsg((char*)bitString1, "1234567890ABCDEF") << '\n';
    testNumber++;
    cout << testNumber << ": " << testMsg((char*)bitString2, "12F4A9969BAB7C0A") << '\n' << '\n';
    testNumber++;

    // Вычислительные операции на корректном инпуте
    cout << testNumber << ":  " << testMsg((char*)(bitString1 + bitString2),
                                "2529000F2C5749F9") << '\n';
    testNumber++;
    cout << testNumber << ":  " << testMsg((char*)(bitString1 - bitString2),
                                "-00C0531E0AFFAE1B") << '\n';
    testNumber++;
    cout << testNumber << ":  " << testMsg((char*)(bitString1 | bitString2),
                                "12F4FFFE9BABFDEF") << '\n';
    testNumber++;
    cout << testNumber << ":  " << testMsg((char*)(bitString1 & bitString2),
                                "1234001090AB4C0A") << '\n';
    testNumber++;
    cout << testNumber << ":  " << testMsg((char*)(bitString1 ^ bitString2),
                                "00C0FFEE0B00B1E5") << '\n';
    testNumber++;
    // Результат операции not с любым числом из данного диапазона находится вне диапазона,
    // т.к. not для [0, 7] это [8, F], а макс. значение старшего разряда -- 7
    cout << testNumber << ":  " << testMsg((char*)~bitString1,
                                "EDCBA9876F543210") << '\n' << '\n';
    testNumber++;

    // Операция присваивания
    BitString assignedBitString = bitString1;
    cout << testNumber << ":  " << testMsg((char*)assignedBitString,
                                "1234567890ABCDEF") << '\n' << '\n';
    testNumber++;

    // Некорректный инпут
    bitString1 = BitString("12345678ABCDEFGH"); // буковы вне A-F
    cout << testNumber << ":  " << testMsg((char*)bitString1, "12345678ABCDEFGH") << '\n';
    testNumber++;
    bitString1 = BitString("BADA55D11D051337"); // заведомый оверфлоу (вне -7FFFFFFFFFFFFFFF до 7FFFFFFFFFFFFFFF)
    cout << testNumber << ":  " << testMsg((char*)bitString1, "BADA55D11D051337") << '\n';
    testNumber++;

    return 0;
}
