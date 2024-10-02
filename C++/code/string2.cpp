#include<iostream>
using namespace std;
int main(){
   // This is how we create string object
   string str;
   cout<<"Enter a String:";
   /* This is used to get the user input
    * and store it into str
    */
   getline(cin,str);
   cout<<"You entered: ";
   cout<<str<<endl;
   return 0;
}
