#include<iostream>

using namespace std;

class node{
 public:
    int data;
    node* next;

    node(){
        data = 0;
        node* second = new node(1);
        next = NULL;
    }
    node(int data){
        this->data = data;
        next = NULL;
    }
    node(int data,  node* next){
        this->data = data;
        this->next = next;
    }
    
};

node* reverse(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    node* temp = head;

    node* prev = NULL;
    node* curr = head;
    node* next;

    while(curr != NULL){
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* middle(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    node* fast = head->next;
    node* slow = head;

    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        }
    }

    return slow;
}

int main(){

    return 0;
}