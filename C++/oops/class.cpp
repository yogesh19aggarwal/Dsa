#include<iostream>
using namespace std;

/*class Demo{
    int num = 10;
    char a='a';
    public:
    void fun(){
        cout<<num;
        num=16;
        cout<<num;
    }
};*/

class Demo
{
        public:

    int a=10;
    public:
    void fun()
    {
        cout<<"hello"<<a<<endl;
    }
    Demo(int a){
        fun();
        cout<<a<<endl;
    }
};


int main(){
    // constructor
    Demo(2);
   // Demo obj(2);
    //obj.fun();
    Demo(3);

    // destructor********

    
    return 0;
}