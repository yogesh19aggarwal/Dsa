#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
};

// struct node * root = NULL;

void insert(struct node * pt , int data){
    if(pt == NULL){
        pt->data = data;
        pt->left = NULL;
        pt->right = NULL;
        return;
    }
    if(pt->left == NULL){
        struct node * first = (struct node *)malloc(sizeof(struct node));
        pt->left = first;
        pt->left->data = data;
        first->left = NULL;
        first->right = NULL;
        return;
    }
    if(pt->right == NULL){
        struct node * first = (struct node *)malloc(sizeof(struct node));
        pt->right = first;
        pt->right->data = data;
        first->left = NULL;
        first->right = NULL;
        return;
    }
    cout<<"cannot insert"<<endl;
    return;
}
int main(){
    struct node * root = NULL;

    return 0;
}