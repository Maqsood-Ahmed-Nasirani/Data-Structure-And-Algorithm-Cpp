#include <iostream>
using namespace std;


int main(void){

    int a = 10;//stores in stack

    int *ptr = new int(); //allocate memory in heap
    *ptr = 20; //ptr is in stack but it's point to int that is present in heap

    delete(ptr);//deallocate memory in heap

    ptr = new int[4];// allocate memory of array of size 4 integers in heap

    delete[] ptr; //deallocate memory of array
    //ptr is dangling pointer b/c it's points to nothing 

    ptr = NULL;

    return 0;
}