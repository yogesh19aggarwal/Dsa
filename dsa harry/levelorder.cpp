#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;

    node(int val){
        data = val;
        left =  NULL;
        right =  NULL;
    }        
};

void insert(struct node * root , int val){
    if(root == NULL){
        struct node * n = new node(val);
        root = n;
        return;
    }
    struct node * prev;
    while(root != NULL){
        prev = root;

        if(root->data = val){
            return;
        }
        if(root->data > val){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node * n = new node(val);

    if(val > prev->data){
        prev->right = n;
    }
    else{
        prev->left = n;
    }
}

void printLevelOrder(node * root){
    if(root == NULL){
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * n = q.front();
        q.pop();
        if(n != NULL){
            cout<<n->data<<" ";
            if(n->left != NULL){
                q.push(n->left);
            }
            if(n->right != NULL){
                q.push(n->right);
            }
        }
        else if(!q.empty()){
            // q.pop();
            q.push(NULL);
        }
    }
}

int sumAtK(struct node * root , int k){
    if(root == NULL){
        return -1;
    }
    int sum = 0 ;
    int level = 0;

    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * n = q.front();
        q.pop();

        if(n != NULL){
            if(level == k){
                // cout<<n->data<<" ";
                sum += n->data;
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int sumOfNodesAtNthLevel(struct node* root, int k)
{
 
    // If the current node is NULL
    if (root == nullptr){
        return 0;
    }

    queue<node*> que;
 
    que.push(root);
 
    // Level is used to track
    // the current level
    int level = 0;
 
    // To store the sum of nodes
    // at the Kth level
    int sum = 0;
 
    // flag is used to break out of
    // the loop after the sum of all
    // the nodes at Nth level is found
    int flag = 0;

    while (!que.empty()) {
 
        // Calculate the number of nodes
        // in the current level
        int size = que.size();
 
        // Process each node of the current
        // level and enqueue their left
        // and right child to the queue
        while (size--) {
            struct node* ptr = que.front();
            que.pop();
 
            // If the current level matches the
            // required level then calculate the
            // sum of all the nodes at that level
            if (level == k) {
 
                // Flag initialized to 1
                // indicates that sum of the
                // required level is calculated
                flag = 1;
 
                // Calculating the sum of the nodes
                sum += ptr->data;
            }
            else {
 
                // Traverse to the left child
                if (ptr->left){
                    que.push(ptr->left);
                }
 
                // Traverse to the right child
                if (ptr->right){
                    que.push(ptr->right);
                }
            }
        }
 
        // Increment the variable level
        // by 1 for each level
        level++;
 
        // Break out from the loop after the sum
        // of nodes at K level is found
        if (flag == 1)
            break;
    }
    return sum;
}
int countNodes(node * root){
    if(root == NULL){
        return 0;
    }
    return (countNodes(root->left) + countNodes(root->right) + 1);
}  

int sumNodes(node * root){
    if(root == NULL){
        return 0;
    }
    return (sumNodes(root->left) + sumNodes(root->right) + root->data);
}

int calcHeight(struct node * root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return(max(lHeight , rHeight) + 1);
}

int calcDiameter(struct node * root){ // time complexity is n^2 so the better approach is just below it
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return (max(currDiameter , max(lDiameter , rDiameter)));
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

int rainwater(vector<int> &a){

    int n = a.size();
    int *left = new int[n];
    int *right = new int[n];

    left[0] = a[0];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1] , a[i]);
    }

    right[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--){
        right[i] = max(right[i+1] , a[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += (min(left[i] , right[i]) - a[i]);
    }

    return ans;
}
int raintwater2(vector<int>& a){  // it does not work according to me and leetcode. 
    stack<int> st;
    int n = a.size() , ans = 0;
    for(int i = 0; i<n; i++){
        while(!st.empty() && a[st.top()] < a[i]){
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff = i - st.top() - 1;
            ans = (min(a[st.top()] , a[i]) - a[cur]) * diff; 
        }
        st.push(i);
    }
    return ans;
}

int *stockSpan(int *price , int n){  //doubt

    int *arr = (int *)malloc(n+1 * sizeof(int));
    arr[0] = 1;
    for(int i=1; i<n; i++){
        int days = 1;
        for(int j = i-1; j>=0; j--){
            if(price[i] >= price[j]){
                days++;
            }
            else{
                arr[i] = days;
                break;
            }
        }
    }

    return arr;
}

void sumReplace(node * root){
    if(root == NULL){
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
    }
}

node * LCA(node * root, int n1, int n2){

    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }
    node * left = LCA(root->left , n1 , n2);
    node * right = LCA(root->right , n1 , n2);
    
    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left != NULL && right == NULL){
        return left;
    }

    return LCA(root->right , n1 , n2);
}

int findDist(node * root , int k, int dist){
    if(root == NULL){
        return -1;
    }
    if(root->data == k){
        return dist;
    }

    int left = findDist(root->left , k , dist+1);
    if(left != -1){
        return left;
    }

    return findDist(root->right, k, dist+1);
}

int distBtwRoots(node * root , int n1 , int n2){
    node * lca = LCA(root , n1 , n2);

    int d1 = findDist(lca , n1 , 0);
    int d2 = findDist(lca , n2 , 0);

    return n1+n2;
}

void flattenR(node * root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    
    if(root->left != NULL){
        flattenR(root->left);

        node* temp = root->right;
        root->right = root->left;

        root->left = NULL;
        node* t = root->right;

        while(t->right != NULL){
            t = t->right;
        }
        t->right = temp;
    }

    flattenR(root->right);
}



int main(){
    int price[] = {100 , 80 , 60 , 70 , 60 , 75 , 85};
    int size = sizeof(price)/sizeof(price[1]);
    // cout<<size<<endl;
    int * arr = stockSpan(price , size);
    // int n = sizeof(arr)/sizeof(arr[1]);

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // int a;
    // cout<< " enter the value of a : ";
    // cin>>a;

    // if(a & 1 == 1){
    //     cout<<" odd "<<endl;
    // }
    // else{
    //     cout<< " even "<<endl;
    // }

    return 0;
}