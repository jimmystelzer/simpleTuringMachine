#include "turingMachine.h"

turingMachine::turingMachine(){
    this->tape1 = new Tape();
    this->tape2 = new Tape();
    this->tape3 = new Tape();
}
void turingMachine::setTM(std::string s){
    tape1->setTapeStr(s);
}
void turingMachine::setInput(std::string s){
    tape2->setTapeStr(s);
}
void turingMachine::reset(){
    this->tape1->reset(false);
    this->tape2->reset(false);
    this->tape3->reset(true);
}
bool turingMachine::exec(){
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
