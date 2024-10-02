#include<iostream>
using namespace std;
struct queue{
    int data;
    struct queue *next;
};
// int isFull(struct queue *r){

// }
// int isEmpty(struct queue *f){

// }
struct queue *f = NULL;
struct queue *r = NULL;

void traversal(struct queue *ptr){
    struct queue * p = ptr;
    while(p != NULL){
        cout<<"element : "<<p->data<<endl;
        p = p->next;
    }
}
void enqueue(/*struct queue *r , struct queue *f,*/ int val){
    struct queue *p = (struct queue *)malloc(sizeof(struct queue));
    if(p == NULL){
        cout<<"overflow"<<endl;
        // return 0;
    }
    else{
        p->data = val;
        p->next = NULL;
        if(f == NULL){
            f=r=p;
        }
        else{
            r->next = p;
            r=p;
        }
        // return r;
    }
}
int dequeue(){
    if(f==NULL){
        return -1;
    }
    else{
        struct queue *p = f;
        int val = p->data;
        f = f->next;
        free(p);
        return val;
    }
}
int main(){

    traversal(f);
    enqueue(23);
    enqueue(25);
    traversal(f);

    cout<<dequeue();
    cout<<endl;

    traversal(f);
    return 0;
}