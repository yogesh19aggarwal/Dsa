#include<iostream>
#include<string>
using namespace std;

void towerOfHanoi(int n, char src , char dest , char helper){
    if(n==0){
        return;
    }
    static int i;
    towerOfHanoi(n-1 , src , helper , dest);
    i += 1;
    cout<<"Move from "<<src<<" to "<<dest<<endl<<i<<endl;
    towerOfHanoi(n-1 , helper , dest , src);
    // i += 1;
}

//  Q remove same adjacent character from a string

string removeDup(string s){
    if(s.length() == 0){
        return "";
    }
    char ch = s[0];
    string ans = removeDup(s.substr(1));

    if(ch == ans[0]){
        return ans;
    }
    return (ch+ans);
}

string moveAllX(string s){
    if(s.length() == 0){
        return "";
    }
    char ch = s[0];
    string ans = s.substr(1);
    if(ch == 'x'){
        return (ans+ch);
    }
    return ch + ans;
}

void subSeq(string s , string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0]; 
    string ros = s.substr(1);

    subSeq(ros , ans);
    subSeq(ros , ans+ch);
}

int main(){
    // towerOfHanoi(3 , 'A' , 'C' , 'B');

    string s = "ffffgwefbwefwefb";
    // cout<<s<<endl;
    // cout<<removeDup(s);
    // cout<<s<<endl;
    subSeq("ABC" , "");
    return 0;
}