#include<iostream>
#include<queue>

using namespace std;

void solve(queue<int> &q, int count, int k){

    if(count == k){
        return;
    }

    int num = q.front();
    q.pop();
    solve(q, count+1, k);

    q.push(num);
}

queue<int> revK(queue<int> q, int k){

    solve(q, 0, k);

    int i = q.size() - k;

    while(i > 0){
        int num = q.front();
        q.pop();

        q.push(num);
        i--;
    }

    return q;
}

void traversal(queue<int> q){

    while(!q.empty()){
        cout<<q.front()<<", ";
        q.pop();
    }cout<<endl;
}

int main(){

    string A = "abbbcdssj";

    vector<int> v(26, 0);
		    
		    
	for(int i = 0; i < A.length(); ++i){
    
	    int num = A[i] - 'a';
        
	    v[num]++;
	}

    for(auto i: v){
        cout<<i<<", ";
    }

    
    return 0;
}