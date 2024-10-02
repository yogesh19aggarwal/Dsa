#include <iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<"A";
		}
};
class B:public A{  	//single level with B
	public:
		B(){
			cout<<"B";
		}
};
class C:public A{	//multilevel with A & B
	public:
		C(){
			cout<<"C";
		}
};

class D:public B,public C{
	public:
		D(){
			cout<<"D";
		}
};

int main(){
	B b;
	// b.display();
	D d;
	
}


