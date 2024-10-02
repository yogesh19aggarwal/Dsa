#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node{

    public:
     int data;
     Node* left;
     Node* right;

     Node(){
        data = -1;
        left = NULL;
        right = NULL;
     }
     Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
     }
};

void buildTree(Node* root){

    queue<Node*> q;

    int data;
    cout<<"Enter the data for root: "<<endl;
    cin>> data;

    if(data == -1){
        return;
    }

    root = new Node(data);
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter the data for leftNode: "<<endl;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter the data for rightData: "<<endl;
        cin>>leftData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

vector<int> zigZagTraversal(Node* root){

    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;
    while(!q.empty()){

        int size = q.size();

        vector<int> ans(size);
        for(int i = 0 ; i < size; ++i){

            Node* temp = q.front();
            q.pop();

            int index = leftToRight ? i : size-1-i;

            ans[index] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        leftToRight = !leftToRight;
        for(auto i: ans){
            result.push_back(i);
        }
    }

    return result;
}

void traversalLeft(Node* root, vector<int> &ans){

    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->left){
        traversalLeft(root->left, ans);
    }else{
        traversalLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int> &ans){

    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans){

    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right, ans);
    }else{
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundary(Node* root){

    vector<int> ans;

    if(root == NULL){
        return ans;      
    }
    ans.push_back(root->data);

    traversalLeft(root->left, ans);

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    traverseRight(root->right, ans);
}