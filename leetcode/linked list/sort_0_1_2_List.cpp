#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

Node* sortList1(Node* head){

     if(head == NULL){
        return NULL;
    }
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else{
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if( zeroCount == 0 && oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(zeroCount == 0 && oneCount == 0 && twoCount != 0){
            temp->data = 2;
            twoCount--;
        }

        temp = temp->next;
    }

    return head;
}

void inertAtTail(Node* &tail, Node* curr){

    tail -> next = curr;
    tail = curr;
}

Node* sortList2(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr != NULL){

        int val = curr->data;

        if(val == 0){
            inertAtTail(zeroTail, curr);
        }

        else if(val == 1){
            inertAtTail(oneTail, curr);
        }
        else if(val == 2){
            inertAtTail(twoTail, curr);
        }

        curr = curr->next;
    }

    if(oneHead->next != NULL ){
        zeroTail->next = oneHead->next;
    }

    if(twoHead->next != NULL){
        oneTail->next = twoHead->next;
    }

    return zeroHead->next;
}
int main(){

    return 0;
}