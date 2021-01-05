#include <Testing/Testing.hpp>
#include <iostream>
#include <sstream>
#include <List/List.hpp>
#include <BitString/BitString.hpp>

using namespace Testing;
using namespace std;

int main() {
    int testNumber = 1;

    ostringstream oss;
    
    // Тесты с int 
    List<int> intList;

    intList.append(new int(1));
    intList.append(new int(2));
    intList.append(new int(3));
    oss << intList;
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), 
        "[1, 2, 3]") << '\n';
    oss.str("");
    oss.clear();
    testNumber++;

    oss << *(intList.pop());
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), 
        "3") << '\n';
    oss.str("");
    oss.clear();
    testNumber++;

    // Тесты с float
    List<float> floatList;

    floatList.append(new float(1.1));
    floatList.append(new float(2.2));
    floatList.append(new float(3.3));
    oss << floatList;
    char *ossContains = (char*)oss.str().c_str();
    cout << testNumber << ": " << testMsg(ossContains, 
        "[1.1, 2.2, 3.3]") << '\n';
    oss.str("");
    oss.clear();
    testNumber++;

    oss << *(floatList.pop());
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), 
        "3.3") << '\n';
    oss.str("");
    oss.clear();
    testNumber++;

    // Тесты с BitString
    List<BitString> bitStringList;

    bitStringList.append(new BitString("00DEC0DEFA11ED00"));
    bitStringList.append(new BitString("00ACCE55DE91ED00"));
    bitStringList.append(new BitString("0063111EDBEEF000"));
    oss << bitStringList;
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), 
        "[00DEC0DEFA11ED00, 00ACCE55DE91ED00, 0063111EDBEEF000]") << '\n';
    oss.str("");
    oss.clear();
    testNumber++;

    oss << *(bitStringList.pop());
    cout << testNumber << ": " << testMsg((char*)oss.str().c_str(), 
        "0063111EDBEEF000") << '\n';
    oss.str("");
    oss.clear();
    testNumber++;

    return 0;
}
