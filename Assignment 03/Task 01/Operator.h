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
    
};
#endif
