#include "turingMachine.h"

turingMachine::turingMachine(){
    this->tape1 = new Tape();
    this->tape2 = new Tape();
    this->tape3 = new Tape();
    this->state = new std::string("");
    this->direction = new std::string("");
    this->character = new std::string("");
    this->newState = new std::string("");
    this->newCharacter = new std::string("");
    this->bitsAlphabet = 0;
}
void turingMachine::setTM(std::string s){
    tape1->reset(true);
    tape1->setTapeStr(s);
}
void turingMachine::setInput(std::string s){
    tape2->reset(true);
    tape2->setTapeStr(s);
}
void turingMachine::reset(){
    this->tape1->reset(false);
    this->tape2->reset(false);
    this->tape3->reset(true);

    this->state = new std::string("");
    this->direction = new std::string("");
    this->character = new std::string("");
    this->newState = new std::string("");
    this->newCharacter = new std::string("");
}

bool turingMachine::exec(){
    this->tape1->goRight();
    return true;
}

std::string turingMachine::leftTapeView1(){
    return this->tape1->leftTapeView();
}
std::string turingMachine::middleTapeView1(){
    return this->tape1->middleTapeView();
}
std::string turingMachine::rightTapeView1(){
    return this->tape1->rightTapeView();
}
std::string turingMachine::leftTapeView2(){
    return this->tape2->leftTapeView();
}
std::string turingMachine::middleTapeView2(){
    return this->tape2->middleTapeView();
}
std::string turingMachine::rightTapeView2(){
    return this->tape2->rightTapeView();
}
std::string turingMachine::leftTapeView3(){
    return this->tape3->leftTapeView();
}
std::string turingMachine::middleTapeView3(){
    return this->tape3->middleTapeView();
}
std::string turingMachine::rightTapeView3(){
    return this->tape3->rightTapeView();
}
void turingMachine::setBitsState(unsigned short int i){
    this->bitsState = i;
}
void turingMachine::setBitsAlphabet(unsigned short int i){
    this->bitsAlphabet = i;
}

std::string turingMachine::stateView(){
    std::ostringstream tmpStr;
    tmpStr << "\u03b4(" << *this->state << "," << *this->character << "):=(" << *this->newState << "," << *this->newCharacter << "," << *this->direction << ")" << std::endl;
    tmpStr << "\u03b2:=a";
    for(unsigned short int i=0;i < this->bitsAlphabet - 2;i++){
        tmpStr << "0";
    }
    tmpStr << "00; R:=a";
    for(unsigned short int i=0;i < this->bitsAlphabet - 2;i++){
        tmpStr << "0";
    }
    tmpStr << "01; L:=a";
    for(unsigned short int i=0;i < this->bitsAlphabet - 2;i++){
        tmpStr << "0";
    }
    tmpStr << "10";
    return tmpStr.str();
}
