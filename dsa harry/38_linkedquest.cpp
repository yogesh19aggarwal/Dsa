#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

// struct node* head = NULL;
void insert(struct node **head, int new_data) {
   struct node* new_node = (struct node*) malloc(sizeof(struct node));
   new_node->data = new_data;
   new_node->next = *head;
   *head = new_node;
//    return new_node;
}
void tranverse(struct node* ptr){
    struct node* p = ptr;
    while(p->next != NULL){
        cout<<p->data<<"->"<<endl;
        p = p->next;
    }
    cout<<p->data<<endl;
}
struct node *insertAtFirst(struct node* &head, int data){
    // struct node *p = head;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = head;
    // head = ptr;
    return ptr;
}

void makeloop(struct node * &head , int pos){

    node * temp = head;
    struct node * startNode;

    int count = 1;
    while(temp->next != NULL){

        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool findloop(struct node* &head) {
    struct node *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
        //    printf("Linked List contains a loop\n");
           return true;
        }
    }
    // printf("No Loop in Linked List\n");
    return false;
}

void removeCycle(node * &head){
    node * fast;
    node * slow;
    slow = fast = head;
    // int count = 1;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);
    // fast->next = NULL;
    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;

}
node * merge(struct node* first, struct node *second){
   
    struct node *merged = NULL;
    struct node * prev = merged;
    while(first->next != NULL){
        merged->data = first->data;
        merged->next = first->next;
        first = first->next;
        merged = merged->next;
    }
    merged->next = second;
    return prev->next;
}

int length(node * head){
    int l = 0;
    node * temp = head;
    while(temp->next != NULL){
        l++;
        temp = temp->next;
    }

    return l;
}

node * kAppend(node * head , int k){

    int len = length(head);
    if(k > len){
        return head;
    }
    
    node * tail = head;
    node * newTail;
    node * newHead;
    int count  = 1;
    while(tail->next = NULL){
        if(count == len-k){
            newTail = tail;
            newTail->next = NULL;
        }
        if(count == (len-k+1)){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    tail->next = head;
    return newHead;
}

int intersection(node * head1 , node * head2){

    int l1 = length(head1);
    int l2 = length(head2);

    int d;
    node * ptr1;
    node * ptr2;

    if(l1 > l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        if(ptr1 == NULL){
            return -1;
        }
        ptr1 = ptr1->next;
        d--;
    }

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

void evenAfterOdd(node * head){

    node * odd = head;
    node * even = head->next;
    node * evenStart = even;

    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    even->next = NULL;
}

int main(){
    struct node *first = NULL , *second = NULL;
    insert(&first,77);
    insert(&first,55);
    insert(&first,44);
    insert(&first,33);
    insert(&first,22);
    insert(&first,11);
    insert(&first,0);
    
    tranverse(first);
    cout<<endl;
    // head->next->next->next = head->next;
    insert(&second,101);
    insert(&second,100);
    insert(&second,99);
    insert(&second,98);
    insert(&second,97);
    insert(&second,96);
    insert(&second,95);
    // findloop(head);
    tranverse(second);
    cout<<endl;

    struct node * third = merge(first , second);
    tranverse(third);

    
    
    
    return 0;
}  