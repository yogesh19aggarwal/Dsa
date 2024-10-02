#include <iostream>
using namespace std;
class Student{  //non-parameterised...
	public:
		Student(){ 
			cout<<"Student Constructor"<<endl;
		}
		
};

class Employee{  //parameterised...
	public:
		int id;
		string name;
		Employee(int id, string name){
		      this->id = id;
		      this->name = name;
		}
		
	void display(){
		cout<<id<<" "<<name<<" "<<endl;
	}

};
int main(){
	Student s1;
	Student s2;
	Employee e1(101, "Krishna");
	Employee e2(102, "Kanchan");
	e1.display();
	e2.display();
	return 0;
}
