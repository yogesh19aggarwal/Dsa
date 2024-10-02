// printing all the prime number in the given range
#include<iostream>
using namespace std;

void primeSieve(int n){
    int prime[n+1];
    prime[0] = prime[1] = false;
    for(int i = 2; i<=n; i++){
        prime[i] = 1;
    }
    if(n < 2){
        cout<<"no prime numbers found "<<endl;
        return;
    }

    for(int i=2; i<=n; i++){
        if(i*i > n){
            break;
        }
        if(prime[i] == 1){
            for(int j = i*i; j<=n; j += i){
                prime[j] = 0;
            }
        }
    }
    cout<<"prime number are : "<<endl;
    for(int i=2; i<=n; i++){
        if(prime[i] == 1){
            cout<<i<<" ";
        }
    }cout<<endl;
}

int main(){
    int n;
    cout<<"size : ";
    cin>>n;

    primeSieve(n);
    return 0;
}