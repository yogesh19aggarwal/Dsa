#include<iostream>
using namespace std;
struct stack{
    int size;
    int top;
    int * arr;
};
int isEmpty(stack *ptr){
    if(ptr->top == -1){
        cout<<"the stack is underflow "<<endl;
        return 1;
    }
    return 0;
}
int isFull(stack * ptr){
    if(ptr->top == ptr->size - 1){
        cout<<"the stack is overflow "<<endl;
        return 1;
    }
    return 0;
}
void push(stack * ptr, int val){
    if(isFull(ptr)){
        cout<<"the stack is overflow you cant push any element"<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pull(stack * ptr){
    if(isEmpty(ptr)){
        cout<<"the stack is underflow you cant pull any element"<<endl;
        return -1;
    }
    else{
        int val;
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(stack* sp, int i){
    int arrind = sp->top - i + 1;
    if(arrind<0){
        return -1;
    }
    return sp->arr[arrind];
}
int stackTop(stack* sp){
    cout<<"the element at top of the stack is : ";
    return sp->arr[sp->top];
}
int stackBottom(stack *sp){
    cout<<"the element at bottom of stack is :";
    return sp->arr[0];
}
int main(){
    stack *sp;
    sp = (struct stack *)malloc(sizeof(stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    cout<<isFull(sp)<<endl<<isEmpty(sp)<<endl;
    push(sp, 12);
    push(sp, 15);
    push(sp, 11);
    push(sp, 17);
    push(sp, 19);
    push(sp, 13);
    push(sp, 9);
    push(sp, 20);
    push(sp, 23);
    push(sp, 54);
    push(sp, 23);
    push(sp, 76);
    
    cout<<endl;
    // cout<<"popped : "<<pull(sp)<<" from the stack"<<endl;
    // cout<<isFull(sp)<<endl<<isEmpty(sp)<<endl;
    // cout<<"peek element is : "<<peek(sp, 7);
    for(int j=1; j<=sp->top+1; j++){
        cout<<"the element at "<<j<<" position is : "<<peek(sp , j)<<endl;
    }
    cout<<stackTop(sp)<<endl<<stackBottom(sp)<<endl;




    return 0;
}