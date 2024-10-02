#include<iostream>
#include<stdio.h>
using namespace std;

struct Student{
    int id;
    char name[10];
    void fun(){
        cout<<"FUNCTION"<<endl;
    }// structure cannot call function
};

int main(){
    Student st1, st2;
    st1.id=10;
    // st1.name= cin.getline('xyz', 10)
    cin.getline(st1.name, 10);

    // string bio;
    // getline(cin, bio);
    // cout<<bio;
    // st1.name= "xyzertyui";
    cout<<st1.name<<endl;
    // cout<<st1.name<<endl;
    // cout<<st1.id<<endl;

}