class BitString {
    long int head;
    unsigned long int tail;
    // -7FFFFFFFFFFFFFFF to 7FFFFFFFFFFFFFFF

    public:
        BitString(char* hexCharseq);
        char* toString();
};