#pragma Once
#include "Stack.h"

void Menu();
bool isOperator(char c);
void setOperatorPrecedence(Operator &o);
string toPostfix(Stack &stack, string &expression);
string toPrefix(Stack &stack, string &expression);


void Menu(){

    cout << "\n----------- Main Menu -----------\n";
    cout << "\n1.Infix to Postfix";
    cout << "\n2.Infix to Prefix";
    cout << "\n3.Exit";
    cout << "\n\nEnter your Choice: ";
}

bool isOperator(char c) {
    
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
    
}

void setOperatorPrecedence(Operator &o){
    
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

string toPostfix(Stack &stack, string &expression){
      
    string PostfixExpression;

    for(int i = 0; i < expression.length(); i++){
        if(isblank(expression[i])){
            continue;
        }else{
            if(isalnum(expression[i])){
                PostfixExpression += expression[i];
                PostfixExpression += " ";
            }else if(expression[i] == '('){
                Operator bracket;
                bracket.setSymbol('(');
                setOperatorPrecedence(bracket);
                stack.Push(bracket);
            } else if(expression[i] == ')'){
                Operator o;
                stack.Pop(o);
                while(o.getSymbol() != '(') {
                    PostfixExpression += o.getSymbol();
                    PostfixExpression += " ";
                    stack.Pop(o);
                }
            }else if (isOperator(expression[i])){
                Operator o;
                o.setSymbol(expression[i]);
                setOperatorPrecedence(o);
                if(stack.isEmpty()){
                    stack.Push(o);
                }else{
                    Operator o1;
                    stack.Pop(o1);
                    if(o1.getSymbol() != '('){
                        if(o1.getValue() >= o.getValue()){
                            PostfixExpression += o1.getSymbol();
                            PostfixExpression += " ";
                            stack.Push(o);
                        }else{
                            stack.Push(o1);
                            stack.Push(o);
                        }
                    }else{
                        stack.Push(o1);
                        stack.Push(o);
                    }
                   
                }
            }
        }
    }
    
    while(!stack.isEmpty()){
        Operator o;
        stack.Pop(o);
        PostfixExpression += o.getSymbol();
    }

    return PostfixExpression;
}

string toPrefix(Stack &stack, string &expression){

    reverse(expression.begin(), expression.end());
    for(int i = 0; i < expression.length(); i++){
        if(expression[i] == '('){
            expression[i] = ')';
        }else if(expression[i] == ')'){
            expression[i] = '(';
        }else{
            continue;
        }
    }

    string PostfixExpression;
    PostfixExpression = toPostfix(stack, expression);
    reverse(PostfixExpression.begin(), PostfixExpression.end());
    
    return PostfixExpression;
}