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
    this->tmpState = new std::string("");
    this->tmpDirection = new std::string("");
    this->tmpCharacter = new std::string("");
    this->tmpNewState = new std::string("");
    this->tmpNewCharacter = new std::string("");
    this->tmpTape3Character = new std::string("");
    this->bitsAlphabet = 0;
    this->bitsState = 0;
    this->controlPass = 0;
    this->controlPar = 0;
    this->par.str("");

}
void turingMachine::setTM(std::string s){
    tape1->reset(true);
    tape1->setTapeStr(s);
}
void turingMachine::setInput(std::string s){
    tape2->reset(true);
    tape2->setTapeStr(s);
}
void turingMachine::reset(bool f){
    if(f){
        this->tape1->reset(false);
        this->tape2->reset(false);
    }else{
        this->tape1->reset(true);
        this->tape2->reset(true);
        this->bitsAlphabet = 0;
        this->bitsState = 0;
    }

    this->tape3->reset(true);

    this->state = new std::string("");
    this->direction = new std::string("");
    this->character = new std::string("");
    this->newState = new std::string("");
    this->newCharacter = new std::string("");
    this->tmpState = new std::string("");
    this->tmpDirection = new std::string("");
    this->tmpCharacter = new std::string("");
    this->tmpNewState = new std::string("");
    this->tmpNewCharacter = new std::string("");
    this->tmpTape3Character = new std::string("");
    this->controlPass = 0;
    this->controlPar = 0;
    this->par.str("");

}
std::string turingMachine::direita(){
    std::ostringstream tmpStr;
    tmpStr << "a";
    for(unsigned short int i=0;i < this->bitsAlphabet - 2;i++){
        tmpStr << "0";
    }
    tmpStr << "01";
    return tmpStr.str();
}
std::string turingMachine::branco(){
    std::ostringstream tmpStr;
    tmpStr << "a";
    for(unsigned short int i=0;i < this->bitsAlphabet - 2;i++){
        tmpStr << "0";
    }
    tmpStr << "00";
    return tmpStr.str();
}

bool turingMachine::exec(){

    if(this->controlPass == 0){
        // Copia fita 2 para 3
        this->execCopyTape();

    }else if(this->controlPass == 1){
        // Lê Fita 3 e coloca caractere codificado em tmpTape2Character
        this->execReadTape3(2);

    }else if(this->controlPass == 2){
        // Lê Fita 1 e define state, character, newState, newCharacter, direction
        this->execReadTape1();

    }else if(this->controlPass == 3){
        // verifica se o caracter da tape 2 valida o estado atual;
        this->execCmpChar();
    }else if(this->controlPass == 4){
        // localiza proximo occorencia do estado;
        this->execFindState();
    }else if(this->controlPass == 5){
        // rebobina
        if(!this->tape1->goLeft()){
            this->controlPass = 4;
        }
    }else if(this->controlPass == 6){
        // Lê Fita 3 e coloca caractere codificado em tmpTape2Character
        this->execReadTape3(4);
    }
    return true;
}

void turingMachine::execCopyTape(){
    if(this->controlPar == 0){
        if((tape2->readCel()).compare(std::string("B"))==0){
            //Inicio da fita
            this->controlPar = 1;
        }else{
            this->par.str("");
            this->par << tape2->readCel();
            this->tape3->writeCel(this->par.str());
            this->tape3->goRight();
            this->tape2->goRight();
        }
    }else if(this->controlPar == 1){
        if(!this->tape2->goLeft()){
            this->controlPar = 0;
            this->controlPass = 1;
        }else{
            this->tape3->goLeft();
        }
    }
}
void turingMachine::execReadTape3(unsigned short int i){
    if(this->controlPar == 0){
        if((tape3->readCel()).compare(std::string("a"))==0){
            //Inicio da fita
            this->controlPar = 1;
            this->par.str("");
            this->par << tape3->readCel();
            tape3->goRight();
        }else if((tape3->readCel()).compare(std::string("B"))==0){
            this->tmpTape3Character->replace(this->tmpTape3Character->begin(),this->tmpTape3Character->end(),this->branco());
            this->controlPar = 0;
            this->controlPass = i; // Passa o controle para  o primeiro passo da fita 1
        }
    }else if(this->controlPar <= this->bitsAlphabet){
        this->par << (tape3->readCel());
        tape3->goRight();
        this->controlPar++;
    }else if(this->controlPar > this->bitsAlphabet){
        this->tmpTape3Character->replace(this->tmpTape3Character->begin(),this->tmpTape3Character->end(),this->par.str());
        for(unsigned short int it=0;it <= this->bitsAlphabet;it++){
            tape3->goLeft();
        }
        this->controlPar = 0;
        this->controlPass = i; // Passa o controle para  o primeiro passo da fita 1
    }
}
void turingMachine::execReadTape1(){
    if(this->controlPar == 0){
        if((tape1->readCel()).compare(std::string("("))==0){
            tape1->goRight();
            this->controlPar = 1;
            this->par.str("");
        }
    }else if(this->controlPar == 1){
        if((tape1->readCel()).compare(std::string("q"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(","))==0){
            this->state->replace(this->state->begin(),this->state->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 2;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 2){
        if((tape1->readCel()).compare(std::string("a"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(","))==0){
            this->character->replace(this->character->begin(),this->character->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 3;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 3){
        if((tape1->readCel()).compare(std::string("q"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(","))==0){
            this->newState->replace(this->newState->begin(),this->newState->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 4;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 4){
        if((tape1->readCel()).compare(std::string("a"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(","))==0){
            this->newCharacter->replace(this->newCharacter->begin(),this->newCharacter->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 5;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 5){
        if((tape1->readCel()).compare(std::string("a"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(")"))==0){
            this->direction->replace(this->direction->begin(),this->direction->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 0;
            this->controlPass = 3;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }
}
void turingMachine::execCmpChar(){
    if(this->controlPar == 0){
        if(this->tmpTape3Character->compare(*this->character)==0){
            tape3->writeCel(*this->newCharacter,this->bitsAlphabet);
            if(this->direction->compare(direita())==0){
                for(unsigned short int i=0;i <= this->bitsAlphabet;i++){
                    tape3->goRight();
                }
            }else{
                for(unsigned short int i=0;i <= this->bitsAlphabet;i++){
                    tape3->goLeft();
                }
                tape3->goLeft();
            }
            this->state->replace(this->state->begin(),this->state->end(),*this->newState);
            this->character->replace(this->character->begin(),this->character->end(),std::string(""));
            this->newState->replace(this->newState->begin(),this->newState->end(),std::string(""));
            this->newCharacter->replace(this->newCharacter->begin(),this->newCharacter->end(),std::string(""));
            this->direction->replace(this->direction->begin(),this->direction->end(),std::string(""));
            this->controlPar = 0;
            this->controlPass = 6;
        }else{
            this->controlPar = 0;
            this->controlPass = 4;
        }
    }
}
void turingMachine::execFindState(){
    if(this->controlPar == 0){
        if((tape1->readCel()).compare(std::string("("))==0){
            tape1->goRight();
            this->controlPar = 1;
            this->par.str("");
        }else if((tape1->readCel()).compare(std::string("B"))==0){
            tape1->goLeft();
            this->controlPar = 0;
            this->controlPass = 5;
        }
    }else if(this->controlPar == 1){
        if((tape1->readCel()).compare(std::string("q"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(","))==0){
            this->tmpState->replace(this->tmpState->begin(),this->tmpState->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 2;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 2){
        if((tape1->readCel()).compare(std::string("a"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(","))==0){
            this->tmpCharacter->replace(this->tmpCharacter->begin(),this->tmpCharacter->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 3;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 3){
        if((tape1->readCel()).compare(std::string("q"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(","))==0){
            this->tmpNewState->replace(this->tmpNewState->begin(),this->tmpNewState->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 4;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 4){
        if((tape1->readCel()).compare(std::string("a"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(","))==0){
            this->tmpNewCharacter->replace(this->tmpNewCharacter->begin(),this->tmpNewCharacter->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 5;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 5){
        if((tape1->readCel()).compare(std::string("a"))==0){
            this->par << (tape1->readCel());
            tape1->goRight();
        }else if((tape1->readCel()).compare(std::string(")"))==0){
            this->tmpDirection->replace(this->tmpDirection->begin(),this->tmpDirection->end(),this->par.str());
            this->par.str("");
            tape1->goRight();
            this->controlPar = 6;
        }else{
            this->par << tape1->readCel();
            tape1->goRight();
        }
    }else if(this->controlPar == 6){
        if((this->tmpState)->compare(*this->state)==0){
            this->state->replace(this->state->begin(),this->state->end(),*this->tmpState);
            this->character->replace(this->character->begin(),this->character->end(),*this->tmpCharacter);
            this->newState->replace(this->newState->begin(),this->newState->end(),*this->tmpNewState);
            this->newCharacter->replace(this->newCharacter->begin(),this->newCharacter->end(),*this->tmpNewCharacter);
            this->direction->replace(this->direction->begin(),this->direction->end(),*this->tmpDirection);
            this->controlPar = 0;
            this->controlPass = 3;
        }else{
            this->controlPar = 0;
            this->controlPass = 4;
        }
    }
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
    tmpStr << "10;" << std::endl << "T3Char:=" << *this->tmpTape3Character;
    return tmpStr.str();
}
