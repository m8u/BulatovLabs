class BitString {
    private:
        long int head;
        unsigned long int tail;
        // -7FFFFFFFFFFFFFFF to 7FFFFFFFFFFFFFFF

    public:
        BitString(char* hexCharseq);
        BitString(long int _head, unsigned long int _tail);

        char* toString();

        static BitString BitString::or(BitString bitString1, BitString bitString2);
        static BitString BitString::and(BitString bitString1, BitString bitString2);
        static BitString BitString::xor(BitString bitString1, BitString bitString2);
        static BitString BitString::not(BitString bitString);
};
