#include <iostream>
using namespace std;
class Parent {
public:
  Parent(){
    cout<<"Hey Guys, I am a Parent"<<endl;
  }
  string collegeName = "CQS";
};
//This class inherits Teacher class
class Child : public Parent {
public:
  Child(){
    cout<<"I am a Child"<<endl;
  }
  string mainSub = "obj";
  string name = "XYZ";
};
int main() {
  Child obj;
  cout<<"Name: "<<obj.name<<endl;
  cout<<"College Name: "<<obj.collegeName<<endl;
  cout<<"Main Subject: "<<obj.mainSub<<endl;
  return 0;
}

