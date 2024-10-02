#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;

    node(int val){
        data = val;
        left =  NULL;
        right = NULL;
    }
};

void insert(struct node * root , int val){
    struct node * prev = NULL;
    node * n = new node(val);
    while(root != NULL)
    {
        prev = root;
        if(root->data == val){
            return;
        }
        if(val < root->data)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    if(prev->data < val){
        prev->right = n;
    }
    else{
        prev->left = n;
    }
}

int search(int inorder[] , int start , int end , int curr){

    for(int i = start; i <= end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}
node * buildTree(int preorder[] , int inorder[] , int start , int end){
    static int ind = 0;
    if(start > end){
        return NULL;
    }

    int curr = preorder[ind];
    ind++;
    struct node * n = new node(curr);
    if(start == end){
        return n;
    }
    int pos = search(inorder , start , end , curr);
    n->left = buildTree(preorder , inorder , start , pos-1);
    n->right = buildTree(preorder , inorder , pos+1 , end);

    return n;   
}

void inOrder(struct node * root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    int n = sizeof(inorder)/sizeof(int);
    node * root = buildTree(preorder , inorder , 0 , n-1);

    inOrder(root);
    return 0;
}