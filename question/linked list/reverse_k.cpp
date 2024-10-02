#include<iostream>

using namespace std;

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

int getLength(node* &head){
    int len = 0;
    node* ptr = head;
    while(ptr != NULL){
        len++;
        ptr = ptr->next;
    }

    return len;
}

node* kReverse(node* &head, int k){

    if(head == NULL){
        return head;
    }

    int len = getLength(head);

    if(k > len){
        return head;
    }

    node* prev = NULL;
    node* curr = head;
    node* next;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(curr != NULL){
        head->next = kReverse(next, k);
    }

    return prev;
}

bool isCircular(node* &head){
    
    if(head == NULL){
        return true;
    }

    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        }

        if(slow == fast && fast == head){
            return true;
        }
        else if(slow == fast){
            return false;
        }
    }while(fast != NULL);

    return false;
}

node* removeLoop(node* head){

    if(head == NULL){
        return head;
    }

    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        }

        if(fast == slow){
            break;
        }
    }while(fast != NULL);

    if(fast == NULL){
        return head;
    }
    else{
        slow = head;
        while(fast->next != slow->next){
            slow = slow->next;
            fast = fast->next;
        }
        if(fast == head){
            while(fast->next != head){
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }

    return head;
}

int main(){

    return 0;
}