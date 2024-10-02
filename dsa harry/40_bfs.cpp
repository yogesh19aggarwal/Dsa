#include<iostream>
using namespace std;
class queue{
public:
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(queue * q){
    if(q->r ==  q->f){
        return 1;
    }
    return 0;
}
int isFull(queue * q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}
void enqueue(queue * q , int data){
    if(isFull(q)){
        return;
    }
    q->r++;
    q->arr[q->r] = data;
}
int dequeue(queue * q){
    if(isEmpty(q)){
        return -1;
    }
    q->f++;
    int val = q->arr[q->f];

    return val;
}

int main(){
    queue q ;
    // cout<<"enter the size of queue : ";
    q.size = 400;
    q.f=q.r=0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // bfs implementation
    int u;
    int i = 6;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    cout<<i<<" ";
    visited[i] = 1;
    enqueue(&q , i); // enqueue i for exploration
    while(!isEmpty(&q)){
        int u = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[u][j] == 1 && visited[j] == 0){
                cout<<j<<" ";
                visited[j] = 1;
                enqueue(&q , j);
            }
        }
        
    }
    return 0;
}