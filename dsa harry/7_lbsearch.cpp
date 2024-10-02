#include<iostream>
//#include<iomanip>
//#include<cmath>
//#include<string>
//#include<algorithm>
//#include<windows.h>
//#include<fstream>
using namespace std;

int linearsearch(int arr[], int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i] == element){
            cout<<"element found at : ";
            return i;
        }        
    }
    cout<<"element not found "<<endl;
    return -1;
}
int bsearch(int arr[], int size, int element){
    int low , mid, high;
    low =0;
    high= size-1;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]==element){
            cout<<"element found at : ";
            return mid;
        }
        else if(element < arr[mid]){
            high = mid-1;
        }
        else{
            low= mid+1;
        }
    }
    cout<<"element not found ";
    return -1;

}

int main(){
    // searching with unsorted array so linear search
    // int arr[]= {1,6,3,8,489,43434,3434,34,3,43,434,4,343,4,345,89};
    // int size = sizeof(arr)/sizeof(int);
    // int element=6;
    // int search = linearsearch(arr, size, element);
    // cout<<search<<endl;

    // searching with sorted array so binary search
    int arr[]= {1,3,6,8,23,434,789};
    int size = sizeof(arr)/sizeof(int);
    int element=6;
    int search = bsearch(arr, size, element);
    cout<<search<<endl;
    return 0;
}