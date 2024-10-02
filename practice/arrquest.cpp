#include<iostream>
using namespace std;

int main(){
    // Q1.Take 10 integer inputs from user and store them in an array. Now, 
    // copy all the elements in another array but in reverse order.

    // int size;
    // cout<<"enter the size of array : ";
    // cin>>size;

    // int arr[size];
    // for(int i=0; i<size; i++){
    //     cout<<"enter the value at "<<i+1<<" : ";
    //     cin>>arr[i];
    //     cout<<endl;

    // }
    // for(int i=0; i<size; i++){
    //     cout<<"value at "<<i+1<<" for arr1 is : "<<arr[i]<<endl;
    // }
    // int arr2[size];
    // for(int i=0; i<size; i++){
    //     // arr2[i] = arr[i];
    //     arr2[i] = arr[size-1-i];
    // }
    // cout<<endl;
    // for(int i=0; i<size; i++){
    //     cout<<"value at "<<i+1<<" for arr2 is : "<<arr2[i]<<endl;
    // }

    // Q2. Write a program to find the sum and product of all elements of an array.

    // int size;
    // cout<<"enter the size of array : ";
    // cin>>size;
    // int sum = 0;
    // int product = 1;

    // int arr[size];
    // for(int i=0; i<size; i++){
    //     cout<<"enter the value at "<<i+1<<" : ";
    //     cin>>arr[i];
    //     cout<<endl;

    // }
    // for(int i=0; i<size; i++){
    //     // cout<<"value at "<<i+1<<" for arr1 is : "<<arr[i]<<endl;
    //     sum += arr[i];
    //     product *= arr[i];
    //     // cout<<"value at "<<i+1<<" for arr1 is : "<<arr[i]<<endl;
    //     cout<<"sum = "<<" "<<sum<<endl<<"product "<<" "<<product<<endl;
    // }


    // Q3. Find a peak element which is not smaller than its neighbours

    // int size;
    // cout<<"enter the size of array : ";
    // cin>>size;

    // int arr[size];
    //  cout<<"enter the value "<<endl;
    // for(int i=0; i<size; i++){
    //     cin>>arr[i];
    //     // cout<<endl;
    // }
    // for(int i=0; i<size; i++){
    //     if(arr[i]>arr[i-1] && arr[i]> arr[i+1]){
    //         cout<<"peak is found at index : "<<i<<endl<<"value at index is : "<<arr[i]<<endl;
    //         break;
    //     }
    // }


    // Q4 . Find minimum and maximum element in an array

    // int size;
    // cout<<"enter the size of array : ";
    // cin>>size;

    // int arr[size];
    // cout<<"enter the value "<<endl;
    // for(int i=0; i<size; i++){
    //     cin>>arr[i];
    // }
    // int min = INT_MAX;
    // int max = INT_MIN;
    // for(int i=0; i<size; i++){
    //     if(arr[i]>max){
    //         max = arr[i];
    //     }
    //     if(arr[i]<min){
    //         min = arr[i];
    //     }
    // }
    // cout<<"min : "<<min<<endl<<"max : "<<max<<endl;
    


    // Q5 . Write a program to reverse an array or string

    int size;
    cout<<"enter the size of array : ";
    cin>>size;

    int arr[size];
    cout<<"enter the value "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int arr1[size];
    int j = 0;
    for(int i=size-1; i>=0; i--){
        arr1[j] = arr[i];
        j++;
    }
    for(int i=0; i<size; i++){
        cout<<arr1[i]<<", ";
    }
    
    return 0;
}