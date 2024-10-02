#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& arr, int k) {

    int size = arr.size();
    vector<int> temp(size);

    for(int i = 0; i < size; i++){

        temp[(i + k) % size] = arr[i]; 
        // int temp = arr[(i + k) % size];
        // arr[(i + k) % size] = arr[i]; 
        // arr[i] = temp;
    }

    // arr.assign(temp.begin(), temp.end());
    arr = temp;

    }

int main(){

    return 0;
}