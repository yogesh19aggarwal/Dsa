#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream fs("filehndling.txt");
	string name;
	cout<<"Enter a name\n";
	cin>>name;
	fs<<name;
	return 0;
}
