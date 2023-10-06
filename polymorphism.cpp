#include <iostream>
using namespace std;
/*
Polymorphism ->
1. Compile Time -> i. function overloading -> ii. operater overlaoding
2. Run time     -> i. virtual function
*/

class A{
    public:
        void func(){
            cout << "I am a function with no arguments\n";
        }
        void func(int a){
            cout << "I am a function with int argument\n";
        }
        void func(double x){
            cout << "I am a function with double argument\n";
        }
};


class complex{
    public:
        complex(int r = 0, int i = 0){
            real = r;
            imag = i;
        }

        complex operator + (complex const &obj){
            complex res;
            res.imag = imag + obj.imag;
            res.real = real + obj.real;
            return res;
        }

        void display(){
            cout << "(" << real << ", i" << imag << ")\n";
        }

    private:
        int real, imag;
};

class base{
    public:
        virtual void print(){
            cout << "This is the base class's print function\n";
        }
        
        void display(){
            cout << "This is the base class's display function\n";
        }
};

class derived: public base{
    public:
        void print(){
            cout << "This is the derived class's print function\n";
        }
        
        void display(){
            cout << "This is the derived class's display function\n";
        }
};


int main(void)
{
    base *basePtr;
    derived d;
    basePtr = &d;
    
    // (*basePtr).print();
    // (*basePtr).display();
    basePtr->display();
    basePtr->print();

    A obj;
    obj.func();// func() will be called
    obj.func(1);//func(int) will be called
    obj.func(1.0); // func(double) will be called

    complex a(12, 7), b(6, 7);
    complex c = a + b;
    c.display();
}