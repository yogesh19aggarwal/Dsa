#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void transverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "element" << ptr->data << endl;
        ptr = ptr->next;
    }
}
struct node *deleteAtFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deletionAtIndex(struct node *head, int index)
{
    int i = 0;
    struct node *p = head;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct node *ptr = p->next;
    // ptr = p->next;
    p->next = ptr->next;
    free(ptr);
    return head;
}

struct node *deleteAtLast(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct node *deletionAtGValue(struct node *head, int data)
{
    int i = 0;
    struct node *p = head;
    struct node *ptr = p->next;
    while (ptr->data != data && p->next !=NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }

    // ptr = p->next;
    if(ptr->data == data){
        p->next = ptr->next;
        free(ptr);
    }
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

    head->data = 11;
    head->next = first;

    first->data = 22;
    first->next = second;

    second->data = 33;
    second->next = third;

    third->data = 44;
    third->next = NULL;

    transverse(head);
    cout << endl;

    // head = deletionAtIndex(head, 2);
    // head = deleteAtFirst(head);
    // head  = deleteAtLast(head);
    head = deletionAtGValue(head, 22);
    transverse(head);
    return 0;
}