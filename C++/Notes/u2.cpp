#include <iostream>
using namespace std;
int sum(int a=1, int b=1, int c=2);
int main(){
   cout<<sum(1)<<endl;
   cout<<sum(1, 2)<<endl;
   cout<<sum(1, 2, 3)<<endl;
   return 0;
}
int sum(int a, int b, int c){
   int z;
   z = a+b+c;
   return z;
}

