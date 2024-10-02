#include<iostream>
#include<queue>

using namespace std;

class node{

 public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = data;
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

    int ans  = max(left, right) + 1;

    return ans;
}

int diameter(node* root){

    if(root == NULL){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);

    int op3 = height(root->left) + 1 + height(root->right);

    int ans = max(op1, max(op2, op3));
    return ans;
}

pair<int, int> diamterFast(node* root){

    if(root == NULL){
        pair<int ,int> p = {0,0};
        return p;
    }
    pair<int, int> left = diamterFast(root->left);
    pair<int, int> right = diamterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;

    int op3 = left.second + right.second + 1;

    pair<int, int> ans ;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int main(){

    // 4 2 3 1 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1 9 -1 -1
    return 0;
}