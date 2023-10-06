#include <iostream>
using namespace std;

int main(void){
    int array[] = { 1, 3, 2, 9, 5, 4, 8, 90, 45, 17};
    int length = sizeof(array)/sizeof(array[0]);

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(!(array[j] > array[i])){
                int temp  = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for(int i = 0; i < length; i++){
        cout<<array[i]<<" ";
    }

    return EXIT_SUCCESS;
}