#include<iostream>

using namespace std;

void insert(int arr[], int size){
    int n;
    cout<<"enter the postion : ";
    cin>>n;

    for(int i=size-1; i>=0; i--){
        if(i>n){
            arr[i+1] = arr[i];
        }
        if(i==n){ 
            cout<<"enter the value at "<<n<<" : ";
            cin>>arr[i];
        }
    }
}

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int arr[size];

    for(int i=0; i<size; i++){
        cout<<"enter the valur of arr at position "<<i+1<<" : ";
        cin>>arr[i];
        cout<<endl;
    }
    for(int i=0; i<size; i++){
        cout<<"valur of arr at position "<<i+1<<" : "<<arr[i]<<endl;
    }

    insert(arr, size);
    for(int i=0; i<size; i++){
        cout<<"valur of arr at position "<<i+1<<" : "<<arr[i]<<endl;
    }

    return 0;
}