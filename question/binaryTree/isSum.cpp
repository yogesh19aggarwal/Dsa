#include<iostream>

using namespace std;

class Node{
 public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<bool, int> isSumTreeFast(Node* root){
        
    if(root == NULL){
        pair<bool, int> p = {true, 0};
        return p;
    }
    
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = {true, root->data};
        return p;
    }
    
    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);
    
    bool left = leftAns.first;
    bool right = rightAns.first;
    
    bool cond = root->data == leftAns.second + rightAns.second;
    
    pair<bool, int> ans;
    if(left && right && cond){
        ans.first = true;
        ans.second = 2 * root->data;
    } else{
        ans.first = false;
    }
    return ans;
}

int main(){

    return 0;
}