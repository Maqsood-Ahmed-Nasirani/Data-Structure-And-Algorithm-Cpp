#include <iostream>
using namespace std;

#define EXIT_SUCCESS 0

int main(void)
{
    int array[] = { 1, 3, 2, 9, 5, 4, 8, 90, 45, 17};
    int length = sizeof(array)/sizeof(array[0]);

    for(int i = 1; i < length; i++){
        int current = array[i];
        int j = i - 1;
        while(array[j]>array[i] && j >= 0){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }

    //printing array members
    for(auto i: array){
        cout<<i<<" ";
    }
    return EXIT_SUCCESS;
}