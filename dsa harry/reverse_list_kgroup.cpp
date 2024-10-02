#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {

        len++;
        head = head->next;
    }

    return len;
}
Node *kReverse(Node *head, int k)
{

    if (head == NULL)
    {
        return NULL;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt = NULL;
    int count = 0;

    int len = getLength(head);

    if (len < k)
    {
        return head;
    }

    while (curr != NULL && count < k)
    {
        nxt = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nxt;
        count++;
    }
    if (curr != NULL)
    {

        head->next = kReverse(nxt, k);
    }

    return prev;
}

int main()
{

    return 0;
}
