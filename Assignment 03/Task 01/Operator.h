#pragma Once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Operator{
    
private:
    
    int value;
    char symbol;
    
public:
    
    void setValue(int Value){
        this->value = Value;
    }
    
    int getValue(){
        return this->value;
    }
    
    void setSymbol(char symbol){
        this->symbol = symbol;
    }
    
    char getSymbol(){
        return this->symbol;
    }
    
};