#include<iostream>
//#include<iomanip>
//#include<cmath>
//#include<string>
//#include<algorithm>
//#include<windows.h>
//#include<fstream>
using namespace std;

int main(){
    int size=3;
    int arr[size];
    int *ptr = arr;
    for(int i=0; i<size; i++){
        cout<<"enter the value of array at"<<i<<" : ";
        cin>>arr[i];
    }

    for(int i=0; i<size; i++){
        cout<<i<<" : "<<arr[i]<<" "<<endl;
    }
    cout<<"*ptr = "<<*ptr<<"\nptr = "<<ptr<<"\n*ptr+1 = "<<*ptr+2;
    return 0;
}