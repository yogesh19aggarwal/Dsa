#include<iostream>

using namespace std;

class node{
 public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        node* left = NULL;
        node* right = NULL;
    }
};

void inorder(node* root, int &count){
    if(root == NULL){
        return;
    }

    inorder(root->left, count);
    
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    inorder(root->right, count);
}

int noOfLeaf(node* root){

    int cnt = 0;

    inorder(root, cnt);

    return cnt;
}

int main(){

    return 0;
}