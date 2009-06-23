#ifndef TAPE_H
#define TAPE_H

#include <string>

class Tape{
    private:
        std::string *tapestr;
        unsigned int pos;

    public:
        Tape();
        ~Tape();
        void setTapeStr(std::string s);
        void reset(bool full);
        bool goLeft();
        bool goRight();
        std::string readCel();
        void writeCel(std::string s);
        void writeCel(char s);

        std::string leftTapeView();
        std::string middleTapeView();
        std::string rightTapeView();
};

#endif // TAPE_H
