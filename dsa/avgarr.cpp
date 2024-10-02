#include<iostream>

using namespace std;

int main(){
    // int size;
    // int avg, sum, count=0;


    // cout<<"enter the size of array : ";
    // cin>>size;
    // int arr[size];

    // for(int i=0; i<size;i++){
    //     cout<<"enter the value of array at "<<i<<" : ";
    //     cin>>arr[i];
    // }
    // for(int i=0; i<size;i++){
    //     cout<<" the value of array at "<<i<<" : "<<arr[i]<<endl;
    //     // cin>>arr[i];
    //     count++;
    //     sum += arr[i]; 
    // }
    // avg = sum/count;
    // cout<<avg<<endl;
    
    // Q write a program to find final balance amount in the account of account holder 
    // on cummulative interest of 5 years @ 5% on deposit of 3 lakh rupees
    float iamnt;
    cout<<"enter the initial amount : ";
    cin>>iamnt;

    int SIZE=2;
    float arr[SIZE];
    arr[0] = iamnt + (iamnt* 0.05);
    int i =1 ;
    while(1){
        char ans;
        cout<<"do you want to break your fd "<<"after just "<<i<<" year (Y/N) : ";
        cin>>ans;
        if(ans == 'y' ||ans == 'Y'){
            break;
        }
        arr[SIZE]=arr[SIZE]+1; 
        arr[i] = arr[i-1] + (arr[i-1]* 0.05);
        i++;
    }
    cout<<"final balance = "<<arr[i-1]<<endl;
    return 0;
}  
