#include <Testing/Testing.hpp>
#include <cstring>

char* Testing::testMsg(char* returned, char* expected) {
    char __returned[128]; strcpy(__returned, returned);
    char* message = new char [128];
    if (strcmp(__returned, expected) == 0) {
        strcpy(message, strcat(__returned, " - OK"));
    } else {
        strcpy(message, strcat(strcat(__returned, " - WRONG, expected: "), expected));
    }
    return message;
}
