#include <iostream>
using namespace std;

int main(void){

    int arr[] = { 10, 20, 30, 40 };
    cout<<*arr<<endl;

    int* ptr = arr;
    for(int i = 0; i < 4; i++){
        cout<<*(arr + i)<<endl;//you can access using this method
        //arr++;//illegal
        // cout<<*ptr<<endl; you can access arrays elements using pointer
        // ptr++:
    }

    //pointer to pointer
    cout<<"Pointer to pointer\n";
    int **pptr = &ptr;
    for(int i = 0; i < 4; i++){
        cout<<**pptr<<endl;
        (*pptr)++;
    }

}