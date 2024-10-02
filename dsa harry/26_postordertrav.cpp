#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * createnode(int data){
    struct node * p = (struct node *)malloc(sizeof(struct node));

    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main(){
    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6); 

    p->left = p1;
    p->right = p2;

    struct node *s1 = createnode(5);
    struct node *s2 = createnode(2);
    p1->left = s1;
    p1->right = s2; 

    postorder(p);
    return 0;
}