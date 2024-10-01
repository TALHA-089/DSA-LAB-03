#include<iostream>

using namespace std;

double Multiply(int a, int b);
double Power(int a, int b);
long int fib(int n);
double fact(int n);
void Menu();

double Multiply(int a, int b){
    
    double Product = 0;
    if(b == 1){
        return a;
    }else{
        return Product = a + Multiply(a, b - 1);
    }
   
    
}

double Power(int a, int b){
    double result = 0;
    
    if(b == 0){
        return 1;
    }else{
        return result = a * Power(a, b - 1);
    }
}

long int fib(int n){
    long int Result = 0;
    
    if(n <= 2){
        return 1;
    }else{
        return Result = fib(n - 1) + fib(n - 2);
    }
}

double fact(int n){
    
    if(n == 1){
        return 1;
    }else{
        return n * fact(n - 1);
    }
}

void Menu(){
    cout << "\n-------- Main Menu ---------\n";
    cout << "\n1.Factorial";
    cout << "\n2.Multiplication";
    cout << "\n3.Power";
    cout << "\n4.nth Fibonacci Term";
    cout << "\n5.Exit";
    cout << "\n\nEnter your Choice: ";
}