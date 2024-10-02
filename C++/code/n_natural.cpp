#include <iostream>
using namespace std;
void printnumbers(int initial, int last){
    if (initial <= last) {
        cout << initial << endl;
        printnumbers(initial + 1, last);
    }
}
int main(){
	int num;
	cout<<"Enter a number"<<endl;
	cin>>num;
    printnumbers(1, num);
    return 0;
}
