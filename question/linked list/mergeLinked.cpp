#include<iostream>
#include<vector>

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

node* solve(node* first, node* second){

    if(first->next == NULL){
        first->next = second;
        return first;
    }

    node* curr1 = first;
    node* next1 = curr1->next;

    node* curr2 = second;
    node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){

        if((curr2->data >= curr1->data) && (next1->data >= curr2->data)){

            curr1->next = curr2;

            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = curr1->next;

            if(next1 == NULL){
                curr1->next = curr2;
            }
        }
    }
    return first;
}

node* mergeSorted(node* head1, node* head2){

    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    if(head1->data <= head2->data){
        return solve(head1, head2);
    }
    else{
        return solve(head2, head1);
    }
}

int main(){

    return 0;
}