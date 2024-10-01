#ifndef Functions_h
#define Functions_h
#pragma Once
#include "Stack.h"
#include <sstream>

void Menu();
bool isOperator(char c);
void setOperatorPrecedence(Operator& o);
string toPostfix(Stack& stack, string& expression);
string toPrefix(Stack& stack, string& expression);
double EvaluatePostfix(Stack& stack, string& expression);
double Multiply(int a, int b);
double Power(double a, double b);


void Menu() {

    cout << "\n----------- Main Menu -----------\n";
    cout << "\n1.Infix to Postfix Conversion and Evaluation";
    cout << "\n2.Infix to Prefix";
    cout << "\n3.Power";
    cout << "\n4.Multiply";
    cout << "\n5.Exit";
    cout << "\n\nEnter your Choice: ";
}

bool isOperator(char c) {

    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');

}

void setOperatorPrecedence(Operator& o) {

    switch (o.getSymbol()) {
    case '+':
        o.setValue(2);
        break;
    case '-':
        o.setValue(2);
        break;
    case '*':
        o.setValue(3);
        break;
    case '/':
        o.setValue(3);
        break;
    case '^':
        o.setValue(5);
        break;
    case '%':
        o.setValue(4);
        break;
    case '(':
        o.setValue(6);
        break;
    default:
        return;
    }
}

string toPostfix(Stack& stack, string& expression) {

    string PostfixExpression;

    for (int i = 0; i < expression.length(); i++) {
        if (isblank(expression[i])) {
            continue;
        }
        else {
            if (isalnum(expression[i])) {
                PostfixExpression += expression[i];
                PostfixExpression += " ";
            }
            else if (expression[i] == '(') {
                Operator bracket;
                bracket.setSymbol('(');
                setOperatorPrecedence(bracket);
                stack.Push(bracket);
            }
            else if (expression[i] == ')') {
                Operator o;
                stack.Pop(o);
                while (o.getSymbol() != '(') {
                    PostfixExpression += o.getSymbol();
                    PostfixExpression += " ";
                    stack.Pop(o);
                }
            }
            else if (isOperator(expression[i])) {
                Operator o;
                o.setSymbol(expression[i]);
                setOperatorPrecedence(o);
                if (stack.isEmpty()) {
                    stack.Push(o);
                }
                else {
                    Operator o1;
                    stack.Pop(o1);
                    if (o1.getSymbol() != '(') {
                        if (o1.getValue() >= o.getValue()) {
                            PostfixExpression += o1.getSymbol();
                            PostfixExpression += " ";
                            stack.Push(o);
                        }
                        else {
                            stack.Push(o1);
                            stack.Push(o);
                        }
                    }
                    else {
                        stack.Push(o1);
                        stack.Push(o);
                    }

                }
            }
        }
    }

    while (!stack.isEmpty()) {
        Operator o;
        stack.Pop(o);
        PostfixExpression += o.getSymbol();
    }

    return PostfixExpression;
}

string toPrefix(Stack& stack, string& expression) {

    reverse(expression.begin(), expression.end());
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            expression[i] = ')';
        }
        else if (expression[i] == ')') {
            expression[i] = '(';
        }
        else {
            continue;
        }
    }

    string PostfixExpression;
    PostfixExpression = toPostfix(stack, expression);
    reverse(PostfixExpression.begin(), PostfixExpression.end());

    return PostfixExpression;
}

double EvaluatePostfix(Stack& stack, string& expression) {
    string PostfixExpression = expression;
    Operator Array[100];
    int counter = 0;
   
    for (int i = 0; i < PostfixExpression.length(); i++) {
        if (isalpha(PostfixExpression[i])) {
            Operator o;
            double x;
            o.setSymbol(PostfixExpression[i]);
            cout << "\nEnter the Value of " << o.getSymbol() << ": ";
            cin >> x;
            cin.ignore();
            o.setValue(x);
            Array[counter] = o;
            counter++;
        }
    }

    for (int i = 0; i < PostfixExpression.length(); i++) {
        if (isalpha(PostfixExpression[i])) {
            for (int j = 0; j < counter; j++) {
                if (PostfixExpression[i] == Array[j].getSymbol()) {
                    stack.Push(Array[j]);
                    break;
                }
            }
        } else if (isOperator(PostfixExpression[i])) {
            Operator O1, O2, O3;
            stack.Pop(O2);
            stack.Pop(O1);

        
            if (PostfixExpression[i] == '+') {
                O3.setValue(O1.getValue() + O2.getValue());
            } else if (PostfixExpression[i] == '-') {
                O3.setValue(O1.getValue() - O2.getValue());
            } else if (PostfixExpression[i] == '*') {
                O3.setValue(O1.getValue() * O2.getValue());
            } else if (PostfixExpression[i] == '/') {
                O3.setValue(O1.getValue() / O2.getValue());
            } else if (PostfixExpression[i] == '^') {
                O3.setValue(pow(O1.getValue(), O2.getValue()));
            } else if (PostfixExpression[i] == '%') {
                O3.setValue(fmod(O1.getValue(), O2.getValue()));
            }

            stack.Push(O3);
        }
    }

    Operator result;
    stack.Pop(result);
    return result.getValue();  
}
double Multiply(int a, int b) {

    double Product = 0;
    if (b == 1) {
        return a;
    }
    else {
        return Product = a + Multiply(a, b - 1);
    }


}

double Power(double a, double b) {
    double result = 0;

    if (b == 0) {
        return 1;
    }
    else {
        return result = a * Power(a, b - 1);
    }
}

#endif
