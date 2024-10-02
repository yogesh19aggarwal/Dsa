#include<iostream>
using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
void traversal(struct queue *q){
    for(int i=q->f+1; i<=q->r;i++){
        cout<<q->arr[i]<<" ";
    }
}
bool isFull(struct queue *q){
    if(q->r == q->size-1){
        return true;
    }
    return false;
}
int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q , int val){
    if(isFull(q)){
        cout<<"the stack is full"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q){
    if(isEmpty(q)){
        cout<<"the queue is empty"<<endl;
        return -1;
    }
    else{
        q->f++;
        int val = q->arr[q->f];
        return val;
    }
}
int main(){
    struct queue q;
    q.size = 100;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 21);
    enqueue(&q, 23);
    traversal(&q);

    dequeue(&q);
    cout<<endl;
    // dequeue(&q);
    traversal(&q);

    return 0;
}