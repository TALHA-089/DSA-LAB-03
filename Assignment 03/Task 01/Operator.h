#ifndef Operator_h
#define Operator_h
#pragma Once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Operator{
    
private:
    
    double value;
    char symbol;
    string UID;
public:
    
    void setValue(double Value){
        this->value = Value;
    }
    
    double getValue(){
        return this->value;
    }
    
    void setSymbol(char symbol){
        this->symbol = symbol;
    }
    
    char getSymbol(){
        return this->symbol;
    }

    void setUID(string UID){
        this->UID = UID;
    }

    string getUID(){
        return this->UID;
    }
    
};
#endif
