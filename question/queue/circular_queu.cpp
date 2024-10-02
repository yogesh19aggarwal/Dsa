#include <bits/stdc++.h> 

using namespace std;

class CircularQueue{
    int size;
    int *arr;
    int front;
    int rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n+1;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((front == 0 && rear == size-1) || ((rear+1)%(size) == (front))){
            return false;
        }
        rear = (rear+1)%(size);
        // if(front == -1){
        //     front = 0;
        // }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == rear){
            return -1;
        }

        front = (front+1)%(size);
        int val = arr[front];
        if(front == rear){
            front = 0;
            rear = 0;
        }

        return val;
    }
};

int main(){

    CircularQueue q(3);

    cout<<"enqueue: "<<q.enqueue(2)<<endl;
    cout<<"enqueue: "<<q.enqueue(3)<<endl;

    cout<<"dequeue: "<<q.dequeue()<<endl;

    cout<<"enqueue: "<<q.enqueue(4)<<endl;
    cout<<"enqueue: "<<q.enqueue(6)<<endl;
    cout<<"enqueue: "<<q.enqueue(7)<<endl;

    // cout<<"dequeue: "<<q.dequeue()<<endl;
    // cout<<"dequeue: "<<q.dequeue()<<endl;
    // cout<<"dequeue: "<<q.dequeue()<<endl;

    // q.enqueue(17);
    cout<<"dequeue: "<<q.dequeue()<<endl;

    // q.enqueue(18);
    

    return 0;
}