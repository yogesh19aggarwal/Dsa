#include <iostream>
using namespace std;

class node
{
    public :
    int data;
    class node *next;
};

void transverse(class node *ptr)
{
    while (ptr != NULL)
    {
        cout << "element : " << ptr->data << endl;
        ptr = ptr->next;
    }
}
class node *inserAtFirst(class node *head, int data)
{
    class node *ptr = (class node *)malloc(sizeof(class node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
class node *insertAtIndex(class node *head, int data, int index)
{
    class node *ptr = (class node *)malloc(sizeof(class node));
    class node *p = head;
    int i = 1;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
class node *inserAtLast(class node *head, int data)
{
    class node *ptr = (class node *)malloc(sizeof(class node));
    class node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
class node *delAtFirst(class node *head)
{
    class node *p = head;
    head = head->next;
    free(p);
    return head;
}
class node *delAtIndex(class node *head, int index)
{
    class node *p = head;
    class node *q = p->next;
    int i = 1;
    while (i < index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
class node *delAtLast(class node *head)
{
    class node *p = head;
    class node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
int main()
{
    class node *head;
    class node *first;
    class node *second;
    class node *third;
    head = (class node *)malloc(sizeof(class node));
    first = (class node *)malloc(sizeof(class node));
    second = (class node *)malloc(sizeof(class node));
    third = (class node *)malloc(sizeof(class node));

    head->data = 11;
    head->next = first;

    first->data = 22;
    first->next = second;

    second->data = 44;
    second->next = third;

    third->data = 55;
    third->next = NULL;

    transverse(head);
    cout << endl;
    // head = inserAtFirst(head , 1);
    // transverse(head);
    // cout<<endl;
    head = insertAtIndex(head, 33, 3);
    transverse(head);
    cout << endl;
    // head = inserAtLast(head,66);
    // head = delAtLast(head);
    // transverse(head);
    return 0;
}