#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include <string>
#include <sstream>
#include "tape.h"

class turingMachine{
    private:
        Tape *tape1, *tape2, *tape3;
        std::string *state, *direction, *character, *newState, *newCharacter;
        unsigned short int bitsState, bitsAlphabet;
    public:
        turingMachine();
        void setTM(std::string s);
        void setInput(std::string s);
        void reset();
        bool exec();

        void setBitsState(unsigned short int i);
        void setBitsAlphabet(unsigned short int i);

        std::string leftTapeView1();
        std::string middleTapeView1();
        std::string rightTapeView1();
        std::string leftTapeView2();
        std::string middleTapeView2();
        std::string rightTapeView2();
        std::string leftTapeView3();
        std::string middleTapeView3();
        std::string rightTapeView3();
        std::string stateView();
};

#endif // TURINGMACHINE_H
