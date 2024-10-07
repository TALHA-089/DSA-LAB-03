#include "Functions.h"


int main() {

    Stack stack;
    string expression;

    while (true) {
        Menu();
        int choice;
        string myString;
        getline(cin, myString);
        stringstream(myString) >> choice;
        if (choice == 5) {
            break;
        }
        else if (choice == 1) {
            cout << "\nEnter an Expression: ";
            getline(cin, expression);
            cout << endl;

            if(isValidInfix(expression)){
                expression = toPostfix(stack, expression);
                cout << "\nPostfix Expression: " << expression << endl;
                cout << "\nDo you want to Evaluate the Expression (Y/N)? ";
                char Choice;
                getline(cin, myString);
                stringstream(myString) >> Choice;
                if (Choice == 'y' || Choice == 'Y') {
                    double result;
                    result = EvaluatePostfix(stack, expression);
                    cout << "\nResult: " << result;
                }else if(Choice == 'N' || Choice == 'n'){
                    cout << "\nOkay\n";
                }else{
                    cout << "\nInvalid Input\n";
                }
            }else{
                cout << "\nThe expression is not Valid\n";
            }
            
        }
        else if (choice == 2) {
            cout << "\nEnter an Expression: ";
            getline(cin, expression);
            cout << endl;
            if(isValidInfix(expression)){
                expression = toPrefix(stack, expression);
                cout << "\nPrefix Expression: " << expression << endl;
            }else{
                cout << "\nThe expression is not Valid\n";
            }
        }
        else if (choice == 3) {
            double x, e;
            cout << "\nEnter the Number: ";
            cin >> x;
            cin.ignore();
            cout << "\nEnter the Exponential: ";
            cin >> e;
            cin.ignore();
            double result = Power(x, e);
            cout << "\nResult is: " << result;
        }
        else if (choice == 4) {
            int x, e;
            cout << "\nEnter the Number: ";
            cin >> x;
            cin.ignore();
            cout << "\nEnter the Number: ";
            cin >> e;
            cin.ignore();
            double result = Multiply(x, e);
            cout << "\nResult is: " << result;
        }
        else {
            cout << "\nInvalid Choice!\n";
            cout << "\nTry Again\n";
            continue;
        }
    }

    cout << "\nGoodBye!\n";
    cout << endl;
    return 0;
}
