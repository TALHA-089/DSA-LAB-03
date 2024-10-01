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
            expression = toPostfix(stack, expression);
            cout << "\nPostfix Expression: " << expression << endl;
            cout << "\nDo you want to Evaluate the Expression: ";
            char choice;
            cin >> choice;
            if (choice == 'y') {
                int result;
                result = EvaluatePostfix(stack, expression);
                cout << "\nResult: " << result;
            }
        }
        else if (choice == 2) {
            cout << "\nEnter an Expression: ";
            getline(cin, expression);
            cout << endl;
            expression = toPrefix(stack, expression);
            cout << "\nPrefix Expression: " << expression << endl;
        }
        else if (choice == 3) {
            int x, e;
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