#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class node{
public:
    int data;
    node* next;
    node* arb;

    node(){
        this->data = 0;
        this->next = NULL;
        this->arb = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }
};

void insertAtTail(node* &head, node* &tail, int val){

    node* temp = new node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }else{
        tail->next = temp;
        tail = temp;
        return;
    }
}

node* copyList(node* head){

    node* cloneHead = NULL;
    node* cloneTail = NULL;

    node* temp = head;

    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);

        temp = temp->next;
    }

    unordered_map<node*, node*> oldToNewNode;

    node* org = head;
    node* clone = cloneHead;
    while(org != NULL){
        oldToNewNode[org] = clone;
        org = org->next;
        clone = clone->next;
    }

    org = head;
    clone = cloneHead;

    while(org != NULL){
        clone->arb = oldToNewNode[org->arb];
        clone = clone->next;
        org = org->next;
    }
    return cloneHead;
}

node* copyList2(node* head){

    if(head == NULL){
        return NULL;
    }

    node* cloneHead = NULL;
    node* cloneTail = NULL;

    node* temp = head;

    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);

        temp = temp->next;
    }

    node* old = head;
    node* clone = cloneHead;

    while(old != NULL && clone != NULL){

        node* nxt = old->next;
        old->next = clone;
        old = nxt;

        nxt = clone->next;
        clone->next = old;
        clone = nxt;
    }

    temp = head;

    while(temp != NULL){

        if(temp->next != NULL){
            if(temp->arb != NULL){
                temp->next->arb = temp->arb;
            }else{
                temp->next->arb = NULL;
            }
        }
        temp = temp->next->next;
    }

    old = head;
    clone = cloneHead;

    while(old != NULL && clone != NULL){

        old->next = clone->next;
        old = old->next;

        if(old != NULL){
            clone->next = old->next;
        }
        clone = clone->next;
    }

    return cloneHead;
}

int main(){

    return 0;
}