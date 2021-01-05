#include <Testing/Testing.hpp>
#include <iostream>
#include <sstream>
#include <DecString/DecString.hpp>

using namespace Testing;
using namespace std;

int main() {
    int testNumber = 1;

    ostringstream oss;

    // Методы представления наследника DecString
    DecString decString1 = DecString("FEE1BAD");
    oss << decString1.getNumber();
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), "267262893") << '\n';
    testNumber++;
    oss.str("");
    oss.clear();
    oss << decString1;
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), "00000000000267262893") << '\n' << '\n';
    testNumber++;
    oss.str("");
    oss.clear();

    // Методы конвертации в 8-ю и 16-ю СС
    cout << testNumber << ": " << testMsg(decString1.toOct(), "0000000000001773415655") << '\n';
    testNumber++;
    cout << testNumber << ": " << testMsg(decString1.toHex(), "000000000FEE1BAD") << '\n' << '\n';
    testNumber++;
     
    // Дата создания экземпляра
    printf("%d-%d-%d %d:%d - probably OK, please check manually\n", decString1.dateCreated.tm_year,
                                decString1.dateCreated.tm_mon,
                                decString1.dateCreated.tm_mday,
                                decString1.dateCreated.tm_hour,
                                decString1.dateCreated.tm_min);

    return 0;
}
