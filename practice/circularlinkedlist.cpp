#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
void transverse(struct node *head)
{
    struct node* ptr = head;
    do{
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }while(ptr != head);
    // free(ptr);
}
struct node* insertAtFirst(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    ptr->data = data;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
struct node* insertAtIndex(struct node* head, int data, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    ptr->data = data;
    int i=1;
    while(i < index-1){
        i++;
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node* insertAtLast(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    ptr->data = data;
    while(p->next != head){
        p = p->next;
    }
    ptr->next = head;
    p->next = ptr;
    return head;
}
struct node* insertByGValue(struct node* head,struct node* prenode, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prenode->next;
    prenode->next = ptr;
    return head;
}

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = first;

    first->data = 11;
    first->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = head;

    transverse(head);
    cout<<endl;

    // head = insertAtFirst(head, 0);
    // head = insertAtLast(head, 44);
    head = insertByGValue(head, second, 28);
    transverse(head);
    return 0;
}