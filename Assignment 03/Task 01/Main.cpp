#include "Functions.h"
#include <sstream>

int main(){
    
    Stack stack;
    string expression;

    while(true){
        Menu();
        int choice;
        string myString;
        getline(cin, myString);
        stringstream(myString) >> choice; 
        if(choice == 3){
            break;
        }else if(choice == 1){
            cout << "\nEnter an Expression: ";
            getline(cin,expression);
            cout << endl;
            expression = toPostfix(stack, expression);
            cout << "\nPostfix Expression: " << expression << endl;
        }else if(choice == 2){
            cout << "\nEnter an Expression: ";
            getline(cin,expression);
            cout << endl;
            expression = toPrefix(stack, expression);
            cout << "\nPrefix Expression: " << expression << endl;
        }else{
            cout << "\nInvalid Choice!\n";
            cout << "\nTry Again\n";
            continue;
        }
    }
   
    cout << "\nGoodBye!\n";
    cout << endl;
    return 0;
}