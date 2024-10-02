#include<iostream>
// #include<iomanip>
// #include<cmath>
// #include<string>
// #include<algorithm>
using namespace std;

int main(){
    
    int size;
    int freq;
    int count=0;
    cout<<"enter the size of array : ";
    cin>>size;
    int arr[size];

    for(int i=0; i<size;i++){
        cout<<"enter the value of array at "<<i<<" : ";
        cin>>arr[i];
    }
    cout<<"enter the value of array you want to find freq : ";
    cin>>freq;

    for(int i=0; i<size;i++){
        cout<<" the value of array at "<<i<<" : "<<arr[i]<<endl;
        if(arr[i]==freq){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}