#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void display(node* ptr){
    
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }cout<<endl;
}

void insertAtTail(node* &head, int data){

    node* newNode = new node(data);

    if(head == NULL){
        head = newNode;
        return;
    }
    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

    // return head;
}

node* reverse(node * &head){\

    if(head == NULL){
        return NULL;
    }

    node* prev = NULL; 
    node* curr = head;
    node* aft;

    while(curr != NULL){
        aft = curr->next;

        curr->next = prev;
        prev = curr;
        curr = aft;
    }

    head = prev;

    return head;
} 

int main(){

    // cout<<"hello";
    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    display(head);

    reverse(head);

    display(head);

    return 0;
}