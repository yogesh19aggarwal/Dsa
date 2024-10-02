#include<iostream>
#include<queue>

using namespace std;

class node{
 public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

void buildTree(node* &root){

    queue<node*> q;

    cout<<"Enter the data for root: "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return;
    }

    root = new node(data);

    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        cout<<"Enter the data for left node of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the data for right node of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

pair<bool, int> isBalancedFast(node* root){
    if(root == NULL){
        pair<bool, int> p = {true, 0};
        return p;
    }
       
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool third = abs(left.second - right.second) <= 1;
    
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    
    if(leftAns && rightAns && third){
        ans.first = true;
    } else{
        ans.first = false;
    }
    
    return ans;
}

bool isBalanced(node* root){

    if(root == NULL){
        return true;
    }

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    bool third = abs(height(root->left) - height(root->right)) <= 1;

    if(leftAns && rightAns && third){
        return true;
    } else{
        return false;
    }
}

int main(){

    return 0;
}