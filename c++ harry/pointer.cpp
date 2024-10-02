#include<iostream>

using namespace std;

int main(){

    int a=10;
    int *ptr=&a;
    cout<<&a<<endl;
    cout<<ptr<<endl<<&ptr<<endl<<a<<endl<<*ptr<<endl;

    
    return 0;
}