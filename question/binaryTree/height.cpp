#include<iostream>
#include<queue>
// #include<algorithm>

using namespace std;

class node{

 public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int height(node* root){

    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

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

void levelOrder(node* root){

    if(root == NULL){
        cout<<"Tree is Empty "<<endl;
        return;
    }

    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else{

            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){

    node* root = NULL;

    buildTree(root);
    levelOrder(root);

    cout<<"height is: ";
    cout<<height(root);
    // 4 2 3 1 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1 9 -1 -1
    return 0;
}