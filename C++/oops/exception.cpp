#include<exception>
#include<iostream>

using namespace std;

int main(){
    cout<<2+2<<endl;
    cout<<2*2<<endl;
    cout<<2/2<<endl;
    int a=2;
    int b;
    cout<<"enter the humber : ";
    cin>>b;
    try{
        // cout<<2/0<<endl;
        if(b>0){
            cout<<a/b<<endl;
        }
        else{
            throw"wrong attemp";
        }
    }
    catch(const char* e){
        cerr<<e<<endl;
        // cout<<"failed"<<endl;                                      
    }
    
    cout<<"successfull"<<endl;
    return 0;
}