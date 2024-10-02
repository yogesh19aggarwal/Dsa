#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node * right;
};

struct node * createnode(int data){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}
void preordertrav(struct node * root){
    
    if(root != NULL){
        cout<<root->data<<" ";
        preordertrav(root->left);
        preordertrav(root->right);
    }
}
int main(){
    struct node *p = createnode(2);
    struct node *p1 = createnode(14);
    struct node *p2 = createnode(15); 

    p->left = p1;
    p->right = p2;

    struct node *s1 = createnode(3);
    struct node *s2 = createnode(4);
    p1->left = s1;
    p1->right = s2; 
    preordertrav(p);
    return 0;
}