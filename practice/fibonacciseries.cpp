#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

long long int fib_bottom_up(int n){   //4
    if(n==1 || n==2){
        return 1;
    }
    long long bottom_up[n+1];   //3
    bottom_up[0]=0;
    bottom_up[1]=1;
    // bottom_up[2]=1;
    for(int i=2; i<n; i++){   //i<=3
        bottom_up[i]=bottom_up[i-2]+bottom_up[i-1]; //  1 + 2
    }
    return bottom_up[n];
}
int fib(int n){
    if( n==1 || n==2){
        return 1;
    }
    int result = fib(n-1)+ fib(n-2);
    return result;
}
int fib_memo(int n){
    int memo[n];
    // if(memo[n] != 0){
        // return memo[n];
    // }
    if(n==1 || n==2){
        return 1;
    }
    else
    {
        int result = fib(n-1)+fib(n-2);
        memo[n]= result;
        return result;
    }
}

int main(){
    // cout<<fib_bottom_up(20)<<endl;
    // cout<<fib_bottom_up(35)<<endl;
    // cout<<fib_bottom_up(45)<<endl;
    // // int arr[40];
    // cout<<fib_memo(35)<<endl;
    // cout<<fib_memo(20)<<endl;
    // cout<<fib(20)<<endl;
    // cout<<fib(35)<<endl;
    // cout<<fib(50)<<endl;
    // for(int i=1; i<40; i++){
        // cout<<i<<" = "<<fib(i)<<endl;
    // }
    for(int i=0; i<500; i++){
        cout<<i+1<<" = "<<fib_bottom_up(i)<<endl;
    }
    // cout<<fib_memo(20)<<endl;
    // cout<<fib_memo(35)<<endl;
    // cout<<fib_memo(45)<<endl;
    return 0;
}