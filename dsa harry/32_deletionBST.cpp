#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;
};
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
struct node * createnode(int data){
    struct node * sp = (struct node *)malloc(sizeof(struct node));

    sp->data = data;
    sp->left = NULL;
    sp->right = NULL;

    return sp;
}
void insertBST(struct node * root , int key){
    struct node * prev = NULL;
    // struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node *n = createnode(key);
    while(root != NULL){
        prev = root;
        if(key == root->data){
            cout<<"canot insert";
            return ;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    if(key < prev->data){
        prev->left = n;
    }
    else{
        prev->right = n;
    }
}
struct node * inOrderPredecessor(struct node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node * root , int value){
    struct node * ipre;
    if(root == NULL){
        return NULL;
    }
    // deletion if its leaf node
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
    // search the node to be deleted
        if(value < root->data){
        root->left = deleteNode(root->left , value);
        }
        else if(value > root->data){
            root->right = deleteNode(root->right , value);
        }
    // deletion 
        else{
            ipre = inOrderPredecessor(root);
            root->data = ipre->data;
            root->left = deleteNode(root->left , ipre->data); 
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

    insertBST(p , 12);
    insertBST(p , 56);
    inorder(p);
    // cout<<t3->left->data<<endl<<s4->right->data<<endl;

    deleteNode(p , 14);
    cout<<endl;

    inorder(p);

    return 0;
}