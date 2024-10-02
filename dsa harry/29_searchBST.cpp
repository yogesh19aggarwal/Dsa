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

struct node * search(struct node * root , int key){
    if(root != NULL){
        if(key == root->data){
            cout<<"key is found "<<endl;
            return root;
        }
        else if(key > root->data){
            return search(root->right , key);
        }
        else{
            return search(root->left , key);
        }
    }
    else{
        return NULL;
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

    struct node *sp = search(p , 8);
    if(sp != NULL){
        cout<<"found : "<<sp->data<<endl;
    }
    else{
        cout<<"element not found "<<endl;
    }
    return 0;
}