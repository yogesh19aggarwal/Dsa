#include<iostream>
using namespace std;
class node{
    public:
    int data;
    class node* next;

    node(int val){
        data = val;
        next = NULL;
    }
    node(){};
};

// class node* head = NULL;
void insert(class node **head,int new_data) {
   class node* new_node = (class node*) malloc(sizeof(class node));
   new_node->data = new_data;
   new_node->next = *head;
   *head = new_node;
//    return new_node;
}
void tranverse(class node* ptr){
    class node* p = ptr;
    while(p != NULL){
        cout<<"element : "<<p->data<<endl;
        p = p->next;
    }
}
class node *insertAtFirst(class node *head, int data){
    // class node *p = head;
    class node *ptr = (class node*)malloc(sizeof(class node));

    ptr->data = data;
    ptr->next = head;
    // head = ptr;
    return ptr;
}

void findloop(class node *head) {
    class node *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
           printf("Linked List contains a loop\n");
           return;
        }
    }
    printf("No Loop in Linked List\n");
}
void makeloop(class node * head , int pos){

    node * temp = head;
    class node * startNode;

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
node * merge(class node* &first, class node* &second){

    node * p1 = first;
    node * p2 = second;
    node * dummy = new node(-1);
    node * p3 = dummy;

    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){

            p3->next = p1;

            p3 = p3->next;
            p1 = p1->next;
        }
        else{

            p3->next = p2;

            p3 = p3->next;
            p2 = p2->next;
        }
    }
    while(p1 != NULL){
        p3->next = p1;

        p3 = p3->next;
        p1 = p1->next;
    }
    while(p2 != NULL){

        p3->next = p2;

        p3 = p3->next;
        p2 = p2->next;
    }
    return dummy->next;
}

node * mergeRe(node * &list1 , node * &list2){
    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
    node * result ;
    if(list1->data < list2->data){
        result = list1;
        result->next = mergeRe(list1->next , list2);
    }
    else{
        result = list2;
        result->next = mergeRe(list1 , list2->next);
    }
    return result;
}
int main(){
    class node *first = NULL , *second = NULL;
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

   class node * third = mergeRe(first , second);
    tranverse(third);

    
    
    
    return 0;
}  