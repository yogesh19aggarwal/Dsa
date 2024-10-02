#include <iostream>
using namespace std;
class Demo{
public:
   //Non-Parameterized constructor
   Demo() {
      cout<<"Demo Non-para Constructor"<<endl;
   }
};
int main(void){
   /*creating two objects of class Demo.
    * This means that the default constructor
    * should have been invoked twice.
    */
   Demo obj1;
   Demo obj2;
   return 0;
}

