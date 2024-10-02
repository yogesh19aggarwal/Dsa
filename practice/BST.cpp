#include<iostream>
using namespace std;
struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node * n = (struct node *)malloc(sizeof(struct node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void display(struct node * root){
    if(root != NULL){
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}

struct node * search(struct node * root , int key){
    while(root != NULL){
        if(key == root->data){
            cout<<"data is found "<<endl;
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

void insertBST(struct node * root , int data){
    struct node * n = createnode(data);
    struct node * prev = root;
    while(root != NULL){
        prev = root;
        if(data == root->data){
            cout<<"canot insert "<<endl;
            return;
        }
        else if(data < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    if(data<prev->data){
        prev->left = n;
    }
    else{
        prev->right = n;
    }
}

struct node * predecessor(struct node * root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}
struct node * inorderpre(struct node * root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}
struct node * deleteBSt(struct node * root , int data){
    struct node * prev;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(data < root->data){
        root->left = deleteBSt(root->left , data);
    }
    else if(data > root->data){
        root->right = deleteBSt(root->right , data);
    }
    else{
        prev = inorderpre(root);
        root->data = prev->data;
        root->left = deleteBSt(root->left , prev->data) ;
    }

    return root;
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

    display(p);
    insertBST(p , 12);
    insertBST(p , 56);

    cout<<endl;
    // cout<<t3->left->data<<endl<<s4->right->data<<endl;
    display(p);

    cout<<endl;

    deleteBSt(p , 56);
    deleteBSt(p , 8);

    display(p);
    return 0;
}