#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next;
};

void linkedlisttraversal(struct node * ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}
int main(){
    struct node * head;
    struct node * second;
    struct node * third;

    // allocate memory for nodes in the linked list in heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 7;
    head->next = second; 

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link second and third nodes
    third->data = 22;
    third->next = NULL; 
    linkedlisttraversal(head);
    return 0;
}