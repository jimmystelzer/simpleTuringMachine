#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include <string>

#include "tape.h"

class turingMachine{
    private:
        Tape *tape1, *tape2, tape3;
        std::string *state, *direction, *character;

    public:
        turingMachine();
        ~turingMachine();
        void setTM(std::string s);
        void setInput(std::string s);
        void reset();
        bool exec();

        std::string leftTapeView1();
        std::string middleTapeView1();
        std::string rightTapeView1();
        std::string leftTapeView2();
        std::string middleTapeView2();
        std::string rightTapeView2();
        std::string leftTapeView3();
        std::string middleTapeView3();
        std::string rightTapeView3();
};

#endif // TURINGMACHINE_H
