#include <iostream>
using namespace std;

//function prototypes
template <class dataType>
int binarySearch(dataType* arrayName, int sizeofArray, dataType key);

int main(void){
    int array[] = { 3, 6, 7, 8, 9, 11, 16, 18, 21, 189};
    char findCh, charArray[] = {'a', 'c', 'e', 'f', 'y', 'z'};
    int find, arraySize = sizeof(array)/sizeof(array[0]);
    cout<<"Enter a character to find: ";
    cin>>find;

    int index = binarySearch(array, arraySize, find);
    cout<<index<<endl;

    if(index != -1){
        cout<<charArray[index]<<endl;
    }
    else{
        cout<<"Key not found!"<<endl;
    }
}

template <class dataType>
int binarySearch(dataType *arrayName, int sizeofArray, dataType key){
    int left = 0, right = sizeofArray, midIndex = sizeofArray/2, index = midIndex;
    dataType mid = arrayName[midIndex];

    while(true){
        if(key > mid){
            index = (midIndex + right) / 2;
            mid = arrayName[index];
            midIndex = index;
        }
        
        else if(key < mid){
            index = midIndex/2;
            midIndex = index;
        }

        else if(key == mid){
            return index;
        }
        else{
            return -1;
        }
    }

}