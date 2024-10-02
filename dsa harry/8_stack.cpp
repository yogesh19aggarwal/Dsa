#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}
int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    
    if(isFull(s)){
        cout<<"the stack is full"<<endl;
    }
    else{
        s->top++;
        s->arr[s->top] = 5;
    }
    if(isEmpty(s)){
        cout<<"the stack is empty"<<endl;
    }
    else{
        cout<<s->arr[s->top]<<endl;
        s->top--;
    }
    return 0;
}