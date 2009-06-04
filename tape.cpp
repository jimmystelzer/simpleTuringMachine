#include "tape.h"

Tape::Tape(){
    this->tapestr = new std::string();
    this->pos = 0;
}
Tape::~Tape(){
    delete(this->tapestr);
}
void Tape::setTapeStr(std::string s){

}
bool Tape::goLeft(){
    if (this->pos > 0){
        this->pos--;
        return true;
    }
    return false;
}
bool Tape::goRight(){
    if(this->pos < this->tapestr->length()+1){
        this->pos++;
        return true;
    }
    return false;
}
std::string Tape::readCel(){
    return std::string(&this->tapestr->at(this->pos));
}

std::string Tape::leftTapeView(){
    return this->tapestr->substr(0,this->pos - 1);
}
std::string Tape::middleTapeView(){
    return this->readCel();
}
std::string Tape::rightTapeView(){
    return this->tapestr->substr(this->pos + 1);
}
