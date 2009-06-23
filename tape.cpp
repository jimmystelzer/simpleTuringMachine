#include "tape.h"

Tape::Tape(){
    this->tapestr = new std::string();
    this->pos = 0;
    for(unsigned int i=0;i<10;i++){
        this->tapestr->append("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
    }
}
Tape::~Tape(){
    delete(this->tapestr);
}
void Tape::setTapeStr(std::string s){
    this->tapestr->replace(this->tapestr->begin(),this->tapestr->end(),s);
    for(unsigned int i=0;i<10;i++){
        this->tapestr->append("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
    }
}
void Tape::reset(bool full){
    if(full==true){
        delete(this->tapestr);
        this->tapestr = new std::string("");
        for(unsigned int i=0;i<10;i++){
            this->tapestr->append("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
        }
    }
    this->pos = 0;
}
bool Tape::goLeft(){
    if (this->pos > 0){
        this->pos--;
        return true;
    }
    return false;
}
bool Tape::goRight(){
    if(this->pos < this->tapestr->length()){
        this->pos++;
        return true;
    }
    return false;
}
void Tape::writeCel(std::string s){
    this->writeCel(s.at(0));
}
void Tape::writeCel(char s){
    this->tapestr->replace(this->pos,1,&s);
}

std::string Tape::readCel(){
    return this->tapestr->substr(this->pos,1);
}
std::string Tape::leftTapeView(){
    return this->tapestr->substr(0,this->pos);
}
std::string Tape::middleTapeView(){
    return this->readCel();
}
std::string Tape::rightTapeView(){
    if(this->pos + 1 < this->tapestr->size()){
        return this->tapestr->substr(this->pos + 1);
    }else{
        return std::string("");
    }
}
