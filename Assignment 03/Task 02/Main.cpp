#include "Functions.h"
#include <sstream>

int main(){
    
    double Product = 0;
    double power = 0;
    double Factorial = 0;
    long int Fib = 0;


    while(true){
        Menu();
        string myString;
        int Choice;
        getline(cin, myString);
        stringstream(myString) >> Choice; 


        if(Choice == 5){
            cout << "\nGoodBye!\n";
            break;
        }else if(Choice == 1){
            int x;
            cout << "\nEnter the Number: ";
            cin >> x;
            cin.ignore();
            Factorial = fact(x);
            cout << "\nFactorial: " << Factorial << endl;
        }else if(Choice == 2){
            int x,y;
            cout << "\nEnter the Numbers: ";
            cin >> x >> y;
            cin.ignore();
            Product = Multiply(x, y);
            cout << "\nProduct: " << Product << endl;
        }else if(Choice == 3){
            int x,y;
            cout << "\nEnter the Number and it's Exponential: ";
            cin >> x >> y;
            cin.ignore();
            power = Power(x,y);
            cout << "\nPower: " << power << endl;
        }else if(Choice == 4){
            int x;
            cout << "\nWhich term do you want in the Fibinacci Sequence: ";
            cin >> x;
            cin.ignore();
            Fib = fib(x);
            cout << "\nThat Term is: " << Fib << endl;
        }else{
            cout << "\nInvalid Choice!\n";
            cout << "\nTry Again\n";
        }
    }
    
    return 0;
}
