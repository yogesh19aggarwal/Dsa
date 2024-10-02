#include <iostream>
using namespace std;
class BaseClass {
public:
   void disp(){
      cout<<"Function of Parent Class";
   }
};
class DerivedClass: public BaseClass{
public:
   void disp() {
      cout<<"Function of Child Class";
   }
};
int main() {
   /* Reference of base class pointing to
    * the object of child class.
    */
   BaseClass obj = DerivedClass(); 
   obj.disp();
   return 0;
}
