#pragma once
#include "Operator.h"

const int MaxSize = 30;

class Stack {

private:

    int top;
    Operator stack[MaxSize];

public:

    Stack() {
        top = -1;
    }

    void Push(Operator item) {
        if (isFull()) {
            cout << "\nStack Overflow!\n";
            return;
        }
        else {
            top++;
            stack[top].setValue(item.getValue());
            stack[top].setSymbol(item.getSymbol());
        }
    }

    void Pop(Operator& item) {
        if (isEmpty()) {
            cout << "\nStack Underflow!\n";
            return;
        }
        else {
            item.setValue(stack[top].getValue());
            item.setSymbol(stack[top].getSymbol());
            top--;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MaxSize - 1);
    }

};