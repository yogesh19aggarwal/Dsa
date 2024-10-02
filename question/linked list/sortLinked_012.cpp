#include<iostream>
#include<vector>

using namespace std;

// structure for linked list
class node{ 
 public:
    int data;   
    node* next;

    node(){
        this->data = 0;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
    node(int data, node* next){
        this->data = data;
        this->next = next;
    }
};

// method 1: by data replacement

node* sortList(node* head){

    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    node* temp = head;

    while(temp != NULL){
        if(temp ->data == 0){
            countZero++;
        }
        else if(temp->data == 1){
            countOne++;
        }
        else{
            countTwo++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        
        if(countZero != 0){
            temp->data = 0;
        }
        else if(countOne != 1){
            temp->data = 1;
        }
        else{
            temp->data = 2;
        }

        temp = temp->next;
    }
    return head;
}

// method 2: if data replacement is not allowed 

void insertAtTail(node* &tail, node* curr){
    tail->next = curr;
    tail = tail->next;
}

node* sortList2(node* head){
    if(head == NULL){
        return head;
    }

    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;

    node* oneHead = new node(-1);
    node* oneTail = oneHead;

    node* twoHead = new node(-1);
    node* twoTail = twoHead;

    node* curr = head;

    while(curr != NULL){
        if(curr->data == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(curr->data == 1){
            insertAtTail(oneTail, curr);
        }
        else if(curr->data == 2){
            insertAtTail(twoTail, curr);
        }

        curr = curr->next;
    }
    // merging three list in sorted order
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup curr head
    head = zeroHead->next;

    // deleting extra nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main(){
    
    return 0;
}