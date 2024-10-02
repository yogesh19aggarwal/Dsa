#include<iostream>
#include<iomanip>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<fstream>

using namespace std;

// this will not work 
void swap(int a, int b){ 
    a = a+b;
    b = a-b;
    a = a-b;
}
// this will work because it using pointer reference
void swappointer(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
// this will work because it using call by reference
void swapreferencevar(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

int main(){
    int x=5, y=4;

    cout<<"the value of a is : "<<x<<" the value of b is : "<<y<<endl;

    // swap(x, y); // this will not work
    // cout<<"the value of a is : "<<x<<" the value of b is : "<<y<<endl;

//     swappointer(&x , &y);// using pointer reference
//     cout<<"the value of a is : "<<x<<" the value of b is : "<<y<<endl;

    swapreferencevar(x,y);// this will work because it using call by reference
    cout<<"the value of a is : "<<x<<" the value of b is : "<<y<<endl;
}

