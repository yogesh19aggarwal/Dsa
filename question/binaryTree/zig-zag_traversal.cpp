#include<iostream>
#include<queue>

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
    cout<<"enter the data for root: "<<endl;
    cin>>data;

    if(data == -1){
        return;
    }

    root = new Node(data);

    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        cout<<"enter the data for left node: "<<endl;

        int leftData;
        cin>>leftData;
        
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"enter the data for right data: "<<endl;

        cin>>rightData;

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

        for(int i = 0; i < size; ++i){

            Node* temp = q.front();
            q.pop();

            int index = leftToRight ? i : size-i-1;

            ans[index] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
         leftToRight = !leftToRight;
        for(auto i : ans){
            result.push_back(i);
        }
    }

    return result;
}

int main(){

    return 0;
}