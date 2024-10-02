#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
void traversal(struct node* ptr){
    struct node* p = ptr;
    while(p != NULL){
        cout<<"element : "<<p->data<<endl;
        p = p->next;
    }
}
int isEmpty(struct node *top){
    if(top == NULL){
        cout<<"stack underflow"<<endl;
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct node *top){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if(n == NULL){
        cout<<"stack overflow"<<endl;
        return 1;
    }
    else{
        return 0;
    }
}
struct node *push(struct node *top, int data){
    if(isFull(top)){
        cout<<"stack overflow"<<endl;
        return top;
    }
    else{
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = data;
        p->next = top;
        top = p;
        return top;
    }
}
int pop(struct node **top){
    if(isEmpty(*top)){
        cout<<"stack underflow"<<endl;
        return 0;
    }
    else{
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct node *top, int position)
{
    struct node *n = top;
    for(int i=1; (i< position && n != NULL); i++){
        n = n->next;
    }
    if(n != NULL){
        return n->data;
    }
    else{
        return -1;
    }
}
int stackTop(struct node *top){
    return top->data;
}

int stackBottom(struct node *top){
    struct node *n = top;
    while(n->next != NULL){
        n = n->next;
    }
    return n->data;
}
int main(){
    struct node *top = NULL;
    top = push(top, 11);
    top = push(top, 22);
    top = push(top , 1);
    // int val = pop(&top);
    // cout<<val<<endl;
    traversal(top);
    cout<<endl;

    // cout<<stackBottom(top)<<endl<<stackTop(top)<<endl;
    cout<<pop(&top)<<endl;

    // cout<<peek(top, 6);
    traversal(top);


    return 0;
}