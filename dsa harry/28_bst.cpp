#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node * sp = (struct node *)malloc(sizeof(struct node));

    sp->data = data;
    sp->left = NULL;
    sp->right = NULL;

    return sp;
}
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int isBST(struct node * root){
    static struct node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        // cout<<root->data<<endl;
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1 ;
    }
}
int main(){
    struct node *p = createnode(9);
    struct node *f1 = createnode(4);
    struct node *f2 = createnode(11); 

    p->left = f1;
    p->right = f2;

    struct node *s1 = createnode(2);
    struct node *s2 = createnode(7);
    f1->left = s1;
    f1->right = s2;

    // struct node *s3 = createnode(2);
    struct node *s4 = createnode(19);
    // p2->left = s3;
    f2->right = s4; 

    struct node * t1 = createnode(5);   
    struct node * t2 = createnode(8);   

    s2->left = t1;
    s2->right = t2;

    struct node * t3 = createnode(14);   
    // struct node * t4 = createnode(8);  
    s4->left = t3;

    inorder(p);
    cout<<endl;
    cout<<isBST(p)<<" ";
    return 0;
}