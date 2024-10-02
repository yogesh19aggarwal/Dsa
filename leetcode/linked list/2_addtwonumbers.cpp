#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *top, int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = top;
    // top = p;
    return p;
}
void traversal(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

node* reverseL(node* head){

    node* prev = NULL;
    node* curr = head;
    node* nxt = NULL;

    while(curr != NULL){

        nxt = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nxt;
    }

    return prev;
}

int reverse(int val)
{
    int reverse1 = 0;
    while (val != 0)
    {
        int rem = val % 10;
        reverse1 = reverse1 * 10 + rem;
        val = val / 10;
    }
    return reverse1;
}
struct node *addTwoNumbers(struct node *l1, struct node *l2)
{   
    l1 = reverseL(l1);
    l2 = reverseL(l2);
    struct node *L3 = NULL;
    // struct node *temp = L3;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        L3 = push(L3, sum % 10);
        // L3 = L3->next;
    }
    return L3;
}
int main()
{
    struct node *head = NULL;
    head = push(head, 5);
    head = push(head, 4);
    cout<<"linled list 1 = ";
    traversal(head);
    cout << endl;
    struct node *head2 = NULL;

    head2 = push(head2, 5);
    head2 = push(head2, 4);
    head2 = push(head2, 3);
    cout<<"linled list 2 = ";
    traversal(head2);
    cout << endl;
    cout << endl;

    struct node *p = addTwoNumbers(head, head2);


    cout<<"linled list 3 = ";
    traversal(p);

    return 0;
}