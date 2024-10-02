#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
};  
struct node *start = NULL;
void append(int data){  
    struct node * nptr = (struct node *)malloc(sizeof(struct node));
    nptr->data = data;
    nptr->next = NULL;
    if(start == NULL){
        start = nptr;
    }
    else{
        struct node * temp;
        temp = start;
        while(temp->next == NULL){
            temp = temp->next;
        }
        temp->next = nptr;
    }
}   
int main(){
    
    return 0;
}