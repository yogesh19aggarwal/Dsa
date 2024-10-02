#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

class Student{
    public:
        string name;
        int age;
        string gender;
        // Student(string s, int a, string g){
        //     name=s;
        //     age =a;
        //     gender =g;
        // }
        public:
        void setinfo(){
            cout<<"enter the name of student = ";
            cin.ignore();
            getline(cin, name);
            // cin.ignore();
            //cin>>name; 
            //system("pause");
            cout<<"enter the age of student = ";
            cin>>age;
            cout<<"enter the gender of student = ";
            cin>>gender;
            printInfo();
        }
        
        void printInfo(){
            //for(int i=0; i<=40; i++){
               // cout<<name;
            //}
            cout<<name<<endl<<age<<endl<<gender<<endl;
            
        }
};
int main(){
    // Student a("yogesh aggarwal", 20, "male" );rty
    // a.printInfo();
    // cout<<"enter the name of student = ";
    // getline(cin, a.name);
    // cout<<a.name<<endl;
    Student a,b,c;
    a.setinfo();
    b.setinfo();
    c.setinfo();
    return 0;
}