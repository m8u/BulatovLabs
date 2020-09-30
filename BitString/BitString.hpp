class BitString {
    private:
        long int head;
        unsigned long int tail;
        // -7FFFFFFFFFFFFFFF to 7FFFFFFFFFFFFFFF

    public:
        BitString(char* hexCharseq);
        BitString(long int _head, unsigned long int _tail);

        char* toString();

        static BitString _or(BitString bitString1, BitString bitString2);
        static BitString _and(BitString bitString1, BitString bitString2);
        static BitString _xor(BitString bitString1, BitString bitString2);
        static BitString _not(BitString bitString);
};
