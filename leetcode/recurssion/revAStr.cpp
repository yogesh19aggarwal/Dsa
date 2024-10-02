#include<iostream>
#include<string>
using namespace std;

void reverse(string s){
    if(s.length()==0){
        return;
    }
    string r = s.substr(1);
    reverse(r);
    cout<<s[0];
}

void replacepi(string str){
    if(str.length() == 0){
        return;
    }

    if(str[0] == 'p' && str[1] == 'i'){
        cout<<"3.14";
        replacepi(str.substr(2));
    }
    else{
        cout<<str[0];
        replacepi(str.substr(1));
    }
}
int main(){
    
    string str = "pipppppipppiiiiipi";
    replacepi(str);

    cout<<endl;
    cout<<str<<endl;

    return 0;
}