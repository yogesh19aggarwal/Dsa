#include <stack>

using namespace std;

void insertSorted(stack<int> &s, int element){

	if(s.empty() || (!s.empty() && s.top() < element)){
		s.push(element);
		return;
	}
    
	int n = s.top();
	s.pop();
    	
	insertSorted(s, element);
    
	s.push(n);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}
    
	int num = stack.top();
	stack.pop();
    
	sortStack(stack);
    
	insertSorted(stack, num);
}

int main(){

    return 0;
}