#include<iostream>
#include<cmath>

using namespace std;

void doubt(int n){
    for(int i=1; i<=6; i++){
        long long int a=pow(n,i);
        // cout<<pow(n,i)<<endl;
        cout<<a<<endl;
    }
}

 
int main() {
    // int n;
    // cin>>n;
    // if(n>0 && n<10){
 
    //     for (int i = 1; i <= 2*n-1; i++)
    //     {
    //         if(i<=2*n){
 
    //             for (int j = 1; j <= 2*n-1; j++)
    //             {
    //                 if(j<=i){
    //                     cout<<j<<"";
    //                 }
    //                 else if(j>((2*n-1)-i)){
    //                     cout<<2*n-j<<"";
    //                 }
    //                 else{
    //                     cout<<" ";
    //                 }
    //             }
    //             cout<<endl;
    //         }
    //     }
 
    // }




    // int n=5;

    // for(int i=1; i<n; i++){
    //     for(int j=1; j<=i; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=n-1; i>0; i--){
    //     for(int j=1; j<=i; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }


    // alternative but best method

        // int n=5;
        
        // for(int row=1; row<=2*n-1; row++){
        //     int totalcolInrow;
        //     if(row>n){
        //         totalcolInrow = 2*n-row;
        //     }
        //     else{
        //         totalcolInrow = row;
        //     }
        //     for(int col =0; col<totalcolInrow; col++){
        //         cout<<"* ";
        //     }
        //     cout<<endl;
        // }

    // int n=5;

    // for(int row=1; row<=n; row++){
    //     for(int col=1; col<=n; col++){
    //         if(col> n-row){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
 
    int n;
    cout<<"enter the  number : ";
    cin>>n;
    // int a=n;
    int ans=0;
    for(int i=2; i<=n; i++){
        while(n%i==0) {
                n=n/i;
                ans= ans+i;
        }
    }
    cout<<ans;
    // while (n % 2 == 0) 
    // { 
    // cout << 2 << " "; 
    // n = n/2; 
    // ans=ans+2;
    // } 
    // for (int i = 3; i <= sqrt(n); i = i + 2) 
    // { 
    //     while (n % i == 0) 
    //     { 
    //         cout << i << " "; n = n/i; 
    //         ans=ans+i;
    //     } 
    // } 
    // if (n > 2) {
    // cout << n << " "<<endl;   
    // }
    // cout<<ans;

 	return 0;
}

    