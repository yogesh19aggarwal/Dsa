#include<iostream>
#include<string>
using namespace std;

struct stack
{
    int top;
    int size;
    char *arr;
};
void traversal(struct stack *ptr){
    for(int i=0; i<=ptr->top; i++){
        cout<<"value at "<<i+1<<" : "<<ptr->arr[i]<<endl;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *sp, char data)
{
    if (isFull(sp)){
        cout<<"stack overflow"<<endl;
    }
    else{
        sp->top++;      
        sp->arr[sp->top] = data;
    }
}
char pull(struct stack *sp){
    // if(isEmpty(sp)){
    //     cout<<"stack underflow"<<endl;
    //     return -1;
    // }
    // else{
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    // }
}
char stackTop(struct stack *sp){
    return sp->arr[sp->top];
}
char stackBottom(struct stack *sp){
    return sp->arr[0];
}
int precendence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}
int isOperator(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return 0;
    }
}
char *infixToPostfix(char *infix){
    int length = sizeof(infix)/sizeof(char);
    struct stack *sp = (struct stack *)malloc(sizeof(stack));

    sp->size = length;
    // sp->size = 500;
    sp->top = -1;
    sp->arr = (char *)malloc(length * sizeof(char));

    char *postfix = (char *)malloc((length+1) * sizeof(char));

    int i = 0; // track infix traversal
    int j = 0; // track postfix addition
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;  
        }
        else{
            if(precendence(infix[i]) > precendence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pull(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pull(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}
int main(){
    char inf[] = "a-b+t/6";
    // char * infix = &inf[0];
    cout<<"postfix of given infix is : "<<infixToPostfix(inf)<<endl;
    return 0;
}