#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next;
};
void linkedlisttraversal(struct node * ptr){
    while(ptr!=NULL){
        cout<<"Element : "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}
struct node* insertatfirst(struct node * &head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node* insertatindex(struct node * head, int data, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    int i=0;

    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr; 

    return head;
}

int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    // allocate memory for nodes in the linked list in heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 7;
    head->next = second; 

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link second and third nodes
    third->data = 22;
    third->next = fourth; 

    // Link second and third nodes
    fourth ->data = 33;
    fourth ->next = NULL;

    linkedlisttraversal(head);
    cout<<endl;

    head = insertatfirst(head, 44);
    linkedlisttraversal(head);
    cout<<endl;

    head = insertatindex(head, 55, 3);
    linkedlisttraversal(head);
    cout<<endl;
    return 0;
}