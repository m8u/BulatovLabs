class BitString {
    private:
        long int head;
        unsigned long int tail;
        // -7FFFFFFFFFFFFFFF to 7FFFFFFFFFFFFFFF

    public:
        BitString(char* hexCharseq);
        BitString(long int _head, unsigned long int _tail);

        char* toString();

        BitString BitString::operator | (BitString other);
        BitString BitString::operator & (BitString other);
        BitString BitString::operator ^ (BitString other);
        BitString BitString::operator ~ ();
};
