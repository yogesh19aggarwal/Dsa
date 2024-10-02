#include <iostream>
#include <string>
#include <stack>

using namespace std;

void Reverse(string &s){

    int low = 0;
    int high = s.length()-1;
    while(low < high){
        swap(s[low++], s[high--]);
    }

}
string reverseWords(string s) {
        
    int size = s.length();

    string p = "";

    int high = size-1;
    while(high >= 0){
        string temp = "";
        while( high >= 0 && s[high] != ' '){
            temp.push_back(s[high]);
            high--;
        }
        if(!temp.empty()){
            Reverse(temp);
            p += temp + ' ';
        }   
        temp.clear();
        while( high >= 0 && s[high] == ' '){
            high--;
        }
    }
    
    if(!p.empty()){
        p.pop_back();
    }
    return p;
}

string reverseStringStack(string str){  

    if(str.empty() || str.size() == 1){
        return str;
    }

    stack<char> temp;
    for(auto i : str){
        temp.push(i);
    }
    str.clear();

    while(!temp.empty()){
        str += temp.top();
        temp.pop();
    }

    return str;

}

int main(){

    string str = "hello";
    cout<<reverseStringStack(str)<<endl; 
    return 0;
}