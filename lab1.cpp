#include <iostream>
using namespace std;


class BitString {
    long int head = 0;
    unsigned long int tail = 0;
    // -7FFFFFFFFFFFFFFF to 7FFFFFFFFFFFFFFF

    public:
        BitString(char hexCharseq[16]) {
            int len;
            for (len = 0; hexCharseq[len] != '\0'; len++); 

            int i = len - 1;
            long int powerOfSixteen = 1;
            int sign = hexCharseq[0] == '-'? -1 : 1; 
            for (i; i >= 0 && powerOfSixteen != 0; i--) {
                if (hexCharseq[i] <= 57) {
                    tail += (hexCharseq[i] - 48) * powerOfSixteen; // 0-9
                } else {
                    tail += (hexCharseq[i] - 55) * powerOfSixteen; // A-F
                }
                powerOfSixteen *= 16;
            }
            powerOfSixteen = 1;
            for (i; i >= 0; i--) {
                if (hexCharseq[i] == '-') break;

                if (hexCharseq[i] <= 57) {
                    head += (hexCharseq[i] - 48) * powerOfSixteen * sign;
                } else {
                    head += (hexCharseq[i] - 55) * powerOfSixteen * sign;
                }
                powerOfSixteen *= 16;
            }
            cout << head * 4294967296 + tail * sign << '\n';
        }
};


int main() {

    BitString bitString = BitString("-7FFFFFFFFFFFFFFF");


    return 0;
}