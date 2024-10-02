#include <iostream>
using namespace std;
int main(){
	int num[2][2] = {1,1,1,1};
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cout<<"|"<<num[i][j]<<"|";
		}
		cout<<"\n"<<endl;
	}
    return 0;
}
