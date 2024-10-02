#include <iostream>

using namespace std;

void swapAlternate(int *arr, int size){

    for(int i = 0; i < size; i+2){
        if(i+1 < size){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

int main(){

    return 0;
}