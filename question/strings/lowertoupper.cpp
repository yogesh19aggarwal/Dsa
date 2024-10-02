#include<iostream>
using namespace std;

int main(){

    string str = "asdhnwfhjfhsdff";

    //  convert to upper case
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
    cout<<str<<endl<<endl;

    // convert to lower case
    for(int i = 0; i<str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'z'){
            str[i] += 32;
        }
    }
    cout<<str;
    return 0;
}