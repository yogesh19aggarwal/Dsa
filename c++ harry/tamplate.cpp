#include<iostream>
// #include<iomanip>
// #include<string>
// #include<algoritm>
// #include<cmath>
// #include<fstream>

using namespace std;

template < class t1=int, class t2=int>
class myclass{
public:
    t1 a1;
    t2 a2;
    myclass(t1 a, t2 b){
        this->a1=a;
        this->a2=b;
    }

    void sum(){
        cout<<a1<<endl<<a2<<endl;
        cout<<a1+a2<<endl;
    }
};

template<class t3, class t4>
float funcavg(t3 a, t4 b){
    t4 avg = (a+b)/2;
    return avg;
}

int main(){
    // myclass<float, float> obj(3, 4.5);
    // obj.sum();

    float a;
    a = funcavg(5,2.7);
    cout<<a<<endl;  
    return 0;
}