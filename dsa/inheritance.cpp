#include<iostream>

using namespace std;

class vehicle{
    public:
    int a=10;
    vehicle(){
        cout<<"all the vehicles "<<endl;
    }
    void output(){
        cout<<a;
    }
};
class scooter : public vehicle{
    public:
    scooter(){
        cout<<"it is a two wheeler"<<endl;
    }
    // int b;
};
class car : public vehicle{
    public:
    car(){
        cout<<"it is 4 wheeler "<<endl;
    }
};
class honda : public scooter, public car{
    public:
    honda(){
        cout<<"it is a company"<<endl;
    }
    int b=10;
    void output1(){
        cout<<b;
    }
    // void car();
    // void scooter();
};
int main(){

    honda d;
    // d.output(); it will not run because it is ambiguous
    d.output1();


    return 0;
}