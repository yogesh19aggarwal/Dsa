#include<iostream>
#include<vector>

using namespace std;

int main(){
    int a = 10;
    int *ptr = &a;

    int **ptr1 = &ptr;
    // int *a;

    // cout<<"address of pointing: "<<a<<endl<<"value at that address: "<<*a<<endl;

    // cout<<"at a: "<<a<<endl<<"at ptr: "<<*ptr<<endl<<"at pt1: "<<**ptr1<<endl;

    vector<int> size(5);

    cout<<size.size();
    
    return 0;
}