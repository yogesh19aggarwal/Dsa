#include<iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int val){
        data = val;
        next = NULL;
    }
    node(){};
};
void display(class node * head)
{
    node * n = head;
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

node * insertAtTail(class node * &head , int data){
    class node * n = new node(data);
    if(head == NULL){
        head = n;
        return head;
    }

    class node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return head;
}
node * reverse(node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node * prev = NULL;
    node * curr = head;
    node * next;
    while(curr != NULL){
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

node * reversek(node * &head , int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node * prev = NULL;
    node * curr = head;
    node * next;
    int count = 0;
    while(curr != NULL && count<k){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count++;
    }
    if(next != NULL)
    {
        head->next = reversek(next , k);
    }

    return prev;
}

node * reverseRec(node * head){
    if(head == NULL ||  head->next == NULL){
        return head;
    }
    node * newHead = reverseRec(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}
int main(){
    class node * head = NULL;
    head = insertAtTail(head , 10);
    head = insertAtTail(head , 20);
    head = insertAtTail(head , 30);
    head = insertAtTail(head , 40);
    // cout<<head->data;

    display(head);

    head = reverseRec(head);

    display(head);
    return 0;
}