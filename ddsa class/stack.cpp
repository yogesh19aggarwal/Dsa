#include<iostream>
using namespace std;
struct stack{
    // int val;
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack * a){
    if(a->top == -1){
        // cout<<"stack is empty "
        return 1;
    }
    return 0;
}
int isFull(struct stack *a){
    if(a->top == a->size-1){
        return 1;
    }
    return 0;
}
void push(struct stack * a , int val){
    if(isFull(a)){
        cout<<"stack over flow "<<endl;
        // return;
    }
    else{
        a->top++;
        a->arr[a->top] = val;
    }
}
int pop(struct stack * a){
    if(isEmpty(a)){
        cout<<"stack underflow "<<endl;
        return -1;
    }
    int val;
    val = a->arr[a->top];
    a->top--;
    return val;
}
int peek(struct stack * a){
    if(isEmpty(a)){
        return -1;
    }
    return (a->arr[a->top]);
}
void display(struct stack * a){
    if(isEmpty(a)){
        cout<<"stack underflow"<<endl;
        return;
    }
    for(int i = a->top; i>=0; i--){
        cout<<a->arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // pop(sp);
    push(sp , 0);
    push(sp , 1);
    push(sp , 2);
    push(sp , 3);
    push(sp , 8);
    push(sp , 6);
    push(sp , 9);
    display(sp);
    cout<<endl;



    return 0;
}