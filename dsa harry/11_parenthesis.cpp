#include <iostream>
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
    if(isEmpty(sp)){
        cout<<"stack underflow"<<endl;
        return -1;
    }
    else{
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
char stackTop(struct stack *sp){
    return sp->arr[sp->top];
}
int match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    else if(a == '[' && b == ']'){
        return 1;
    }
    else if(a=='(' && b==')'){
        return 1;
    }
    else{
        return 0;
    }
}

int parenthesisMatching(char *ar) {
    // int length = sizeof(arr)/sizeof(*arr);
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(stack));
    sp->size = sizeof(ar)/sizeof(char);
    // cin >> sp->size;

    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
    for(int i=0; ar[i]!='\0'; i++){
        if(ar[i] == '(' || ar[i] == '{' || ar[i] ==  '['){
            push(sp, ar[i]);
        }
        else if(ar[i] == ')'||ar[i] =='}'||ar[i] ==']'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
                popped_ch = pull(sp);
                if(!match(popped_ch , ar[i])){
                    return 0;
                }
                // return 1;
            }
        }
    }
    if(isEmpty(sp)){
        // cout<<"balanced"<<endl;
        return 1;
    }
    else{
        // cout<<"unbalanced arr"<<endl;
        return 0;
    } 
}


int main()
{
    // struct stack *sp;
    // sp = (struct stack *)malloc(sizeof(stack));
    // // cout << "enter the size of the stack : ";
    // // cin >> sp->size;

    // sp->top = -1;
    // sp->arr = (char *)malloc(sp->size * sizeof(char));
    // push(sp, '2');
    // push(sp, '8');
    // push(sp, '(');
    // push(sp, '3');
    // push(sp, '*');
    // push(sp, '2');
    // push(sp, ')');
    // push(sp, 11);
    // push(sp, 1);
    // push(sp, 6);
    // traversal(sp);
    // cout<<endl;
    // cout<<pull(sp)<<endl;
    // cout<<endl;
    // traversal(sp);
    char a[] = "[9+(8*2)]";
    // char * exp = &a[0] ;
    if(parenthesisMatching(a)){
        cout<<"balanced";
    }
    else{
        cout<<"unblanced"<<endl;
    }
    // string s;
    // s.size();
    return 0;
}