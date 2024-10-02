#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string s) {
    
    string res;
    
    for(auto ch : s){
        if(!res.empty() && res[res.size() - 1] == ch){
            res.pop_back();
        }
        else{
            res+=ch;
        }
    }
    return res;
}

int main(){

    return 0;
}