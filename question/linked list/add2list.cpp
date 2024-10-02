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
};

node* reverse(node* &head){

    node* curr = head;
    node* prev = NULL;
    node* nxt; //= new node();

    while(curr != NULL){
        nxt = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nxt;
    }
    return prev;
}

void insertAtTail(node* &head, node* &tail, int val){

    node* temp = new node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}
node* add(node* first, node* second){

    node* ansHead = NULL;
    node* ansTail = NULL;

    int carry = 0;

    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL){
            val1 = first->data;
        }

        int val2 = 0;
        if(second != NULL){
            val2 = second->data;
        }

        int sum = val1 + val2 + carry;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
    }
    return ansHead;
}

node* addTwoList(node* first, node* second){

    first = reverse(first);
    second = reverse(second);

    node* ans = add(first, second);

    return reverse(ans);
}

int main(){

    return 0;
}