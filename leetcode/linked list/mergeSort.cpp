#include <iostream>

using namespace std;

class node{
public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

node* findMid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node* merge(node* first, node* second){

    // if(first == NULL && second == NULL){
    //     return NULL;
    // }
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    node* dummyNode = new node(-1);
    node* curr = dummyNode;

    while(first != NULL && second != NULL){
        if(first->data < second->data){

            curr->next = first;
            curr = first;
            first = first->next;
        }
        else{
            // node* temp = new node(second->data);
            curr->next = second;
            curr = second;
            second = second->next;
        }
    }
    while(first != NULL){
        // node* temp = new node(first->data);
        curr->next = first;
        curr = first;
        first = first->next;
    }
    while(second != NULL){
        // node* temp = new node(second->data);
        curr->next = second;
        curr = second;
        second = second->next;
    }

    return dummyNode->next;
}

node* mergeSort(node *head) {
    
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* mid = findMid(head);

    node* left = head;
    node* right = mid->next;

    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* result = merge(left, right);

    return result;
}

int main(){

    return 0;
}