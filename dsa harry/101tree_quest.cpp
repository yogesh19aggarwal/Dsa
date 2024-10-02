// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        node* left  = NULL;
        node* right = NULL;
    }
};

int height(node* root){

    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(height(root->left) , height(root->right))+1;

    return ans;
}

int diameter(node* root){ // O(n^2) T.C

    if(root == NULL){
        return 0;
    }
    
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    int ans = max(op1 , max(op2 , op3));
    return ans;
}

pair<int,int> diameterFast(node* root){
    
    if(root == NULL){
        return {0,0};
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1 , max(op2 , op3));
    ans.second = max(left.second , right.second) + 1;

    return ans;
}

int Diameter(node* root){
    return diameterFast(root).first;
}

int calcdiamter(struct node * root , int *height){ // better approach. it has time complexity of n

    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0 , rh = 0 ; 
    int lDiameter = calcdiamter(root->left , &lh);
    int rDiameter = calcdiamter(root->right , &rh);

    int currDiameter = lh + rh + 1 ; 
    
    *height = max(lh , rh)+1;

    return (max(currDiameter , max(lDiameter , rDiameter)));
}

bool checkBt(node* root){ // n^2 approach

    if(root == NULL){
        return true;
    }
    int left = checkBt(root->left);
    int right = checkBt(root->right);

    bool ans = abs (height(root->left) - height(root->right)) <= 1;
    if(left && right && ans){
        return true;
    }
    return false;
}

pair<bool, int> isBalanced(node* root){

    if(root == NULL){
        return {true,0};
    }

    pair<bool, int> left = isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);
    
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff =  abs(left.second - right.second) <= 1;

    pair<bool , int> ans;

    ans.second = max(left.second , right.second) + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }

    else{
        ans.first = false;
    }

    return ans;
}

bool isIdentical(node* root1 , node* root2){

    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    }
    if(root2 == NULL && root1 != NULL){
        return false;
    }

    bool left = isIdentical(root1->left , root2->left);
    bool right = isIdentical(root1->right , root2->right);
    bool value = root1->data == root2->data;

    if(left && right && value){
        return true;
    }
    return false; 
}

pair<bool , int> solve(node* root){
        
    if(root == NULL){
        return {true,0};
    }
    
    if(root->left == NULL && root->right == NULL){
        return {true , root->data};
    }
    
    pair<bool , int> leftAns = solve(root->left);
    pair<bool , int> rightAns = solve(root->right);
    
    bool left = leftAns.first;
    bool right = rightAns.first;
    
    bool count =  root->data == leftAns.second + rightAns.second ;
    
    pair<bool , int> ans;
    
    if(left && right && count){
        ans.first = true;
        ans.second = 2 * root->data ;
    }
    else{
        ans.first = false;
    }
    return ans;
        
}
bool isSumTree(node* root){
    
    return solve(root).first;
}

vector<int> zigzagLevelorder(node* root){

    vector<int> ans;
    if(root == NULL){
        return ans;
    } 

    queue<node*> q;

    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> v(size);

        for(int i = 0; i < size; i++){
            node* n = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;

            v[index] = n->data;
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        leftToRight = !leftToRight;

        for(auto i : v){
            ans.push_back(i);
        }
    }
    return ans;
}

void leftTraversal(node* root , vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right->right)){
        return ;
    }

    ans.push_back(root->data);
    if(root->left){
        leftTraversal(root->left , ans);
    }
    else{
        leftTraversal(root->right , ans);
    }
}

void leafTraversal(node* root , vector<int> &ans){

    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left , ans);
    leafTraversal(root->right , ans);
}

void rightTraversal(node* root , vector<int> &ans){

    if((root == NULL) || (root->left == NULL && root->right->right)){
        return ;
    }

    if(root->right){
        rightTraversal(root->right , ans);
    }
    else{
        rightTraversal(root->left , ans);
    }
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(node* root){

    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);

    // left traversal
    leftTraversal(root->left , ans);

    // left leaf
    leafTraversal(root->left , ans);

    // right leaf
    leafTraversal(root->right , ans);

    // right upper traversal
    rightTraversal(root->right , ans);

    return ans;
}

vector<int> verticalOrder(node* root){

    map<int , map<int , vector<int> > > nodes;  // hd , lvl , node data
    queue < pair<node* , pair<int, int> > > q ; // node , hd , level

    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    q.push({root , {0,0}});

    while(!q.empty()){
        pair<node* , pair<int, int> > temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push({frontNode->left , {hd-1 , lvl+1}});
        }
        if(frontNode->right){
            q.push({frontNode->right , {hd+1 , lvl+1}});
        }
    }

    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}

vector<int> topView(node* root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    map<int , int> topNode; // int1 =  hd  int2 = lvl

    queue<pair<node* , int> > q; // int = hd

    q.push({root , 0});

    while(!q.empty()){
        pair<node* , int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left){
            q.push({frontNode->left , hd-1});
        }
        if(frontNode->right){
            q.push({frontNode->right , hd+1});
        }
    }

    for(auto i : topNode){
        ans.push_back(i.second);
    }

    return ans;

}

int main(){

    return 0;
}