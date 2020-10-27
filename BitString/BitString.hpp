class BitString {
    private:
        long int head;
        unsigned long int tail;
        // -7FFFFFFFFFFFFFFF to 7FFFFFFFFFFFFFFF

    public:
        BitString(char* hexCharseq);
        BitString(long int _head, unsigned long int _tail);

        long int getHead();
        unsigned long int getTail();

        operator char*();

        BitString operator = (BitString other); 
        friend BitString operator + (BitString _this, BitString other);
        BitString operator - (BitString other);
        BitString operator | (BitString other);
        BitString operator & (BitString other);
        BitString operator ^ (BitString other);
        BitString operator ~ ();
};
