#include<iostream>
using namespace std;
struct queue{
    int size;
    int f, r;
    int *arr;
};
void traversal(struct queue *q){
    int i = q->f+1;
    while(i!=q->r+1){
        cout<<q->arr[i]<<" ";
        i = (i+1)%q->size;
    }
        // cout<<q->arr[i]<<" ";
}
void enqueue(struct queue *q , int val){

    if((q->r+1) % q->size == q->f){
        cout<<"queue overflow"<<endl;
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q){
    if(q->r == q->f){
        cout<<"empty queue"<<endl;
        return -1;
    }
    else{
        q->f = (q->f+1)%q->size;
        int val = q->arr[q->f];
        return val;
    }
}
int main(){
    struct queue q;
    q.size = 5;
    q.r = q.f = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 21);
    enqueue(&q, 23);
    enqueue(&q, 26);
    enqueue(&q, 28);
    // enqueue(&q, 21);
    // enqueue(&q, 23);

    cout<<"dequing element : "<<dequeue(&q)<<endl;
    cout<<"dequing element : "<<dequeue(&q)<<endl;
    enqueue(&q, 29);
    enqueue(&q, 30);

    traversal(&q);
    // cout<<"dequing element : "<<dequeue(&q)<<endl;
    // cout<<"dequing element : "<<dequeue(&q)<<endl;
    // cout<<"dequing element : "<<dequeue(&q)<<endl;

    



    return 0;
}