#include<iostream>
using namespace std;

bool isSorted(int *arr , int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    bool restArray = isSorted(arr+1 , size-1 );
    return restArray;
}

void count(int n){
    if(n == 0){
        cout<<n<<endl;
        return ;
    }
    count(n-1);
    cout<<n<<endl;
}

int Sum(int *arr , int size){
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }

    int sum; 
    sum = arr[0] + Sum(arr+1 , size-1);
    return sum;
}
int main(){
    int arr[] = {1,2,3,4,5}; // 15
    int size = 5;

    int sum = Sum(arr , size);
    cout<<sum;
    
    
    return 0;
}