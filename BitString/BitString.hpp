class BitString {
    private:
        long int head;
        unsigned long int tail;
        // -7FFFFFFFFFFFFFFF to 7FFFFFFFFFFFFFFF

    public:
        BitString(char* hexCharseq);
        BitString(long int _head, unsigned long int _tail);

        char* toString();

        BitString BitString::or(BitString other);
        BitString BitString::and(BitString other);
        BitString BitString::xor(BitString other);
        BitString BitString::not();
};
