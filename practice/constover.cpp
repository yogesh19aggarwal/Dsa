#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

class Student{
    public:
    Student(int num1, int num2, int num3){
        cout<<num1+num2+num3<<endl;
    }
    Student(int num1, int num2){
         cout<<num1+num2<<endl;
    }
    Student(){}
    void add(int num1 , int num2){
        cout<<num1+num2<<endl;
    }
};
class Child{
    public :
    void add(int num1 , int num2){
        cout<<num1+num2<<endl;
    }
};


int main(){
    Student obj;
    // obj.Student(3, 5, 9);
    // obj.Student(3,5);
    // Student::add(10, 20);
    return 0;
}