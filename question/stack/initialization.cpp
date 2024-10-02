#include<iostream>
#include<stack>

using namespace std;

class Stack{
    int size;
    int top;
    int *arr;
public:

    Stack(int size){
        this->size = size;
        this->arr = new int[size];
        top = -1;
    }

    void push(int ele){
        top++;
        if(top >= size){
            cout<<"Stack OverFlow"<<endl;
            top--;
            return;
        }
        arr[top] = ele;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        top--;
    }

    int peek(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

};

int main(){

    Stack st(5);
    cout<<st.isEmpty()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<st.peek()<<endl;
    cout<<st.isEmpty()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.push(6);

    
    return 0;
}