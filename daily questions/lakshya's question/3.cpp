#include <iostream>
#include <cmath>
using namespace std;

void winner(int m, int n){  // m=8, n=11 
    int j=1,ayush=0,harshit=0,flag=0;  // m=8 n=11
   cout<<"hello"<<endl;
        while(flag==0){
            if(j%2==0){ //j=1
                harshit+=j; //j=1
                if(ayush>=m || harshit >= n){
                    flag=1;
                }
            }
            else if(j%2!=0){
                ayush+=j;
                if(ayush>=m || harshit >= n){
                    flag=1;
                }
                
            }
            // else if(ayush>=n || harshit >= m){
            //     flag=1;
            // }
            j++;
        }
        if(ayush>harshit) {
            cout<<"Ayush";
        }
        else if(ayush<harshit){
            cout<<"Harshit";
        }
        cout<<endl;
   
}
int main() {
    // int n=3,m=9,t=2;
     // cin>>t;
    
   //  for(int i = 1; i <= t ; i++){
    //     cout<<"m="; cin>>m;
     //    cout<<"n="; cin>>n;
    winner(9,3);
    // }

    return 0;
}