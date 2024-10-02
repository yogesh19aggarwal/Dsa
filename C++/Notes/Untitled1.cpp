#include <iostream>
using namespace std;
int recursion(int n){
	//int i=n;
	cout<<n;
	if(n!=0){
		recursion(n--);
	}
	else{
		return 0;
	}
	
}
int main(){
	recursion(5);
	return 0;
}
