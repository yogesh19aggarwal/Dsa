#include<iostream>
#include<vector>

using namespace std;

class node{
 public:
    int data;
    node* next;
    node(){
        this->data = 0;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
    node(int data, node* next){
        this->data = data;
        this->next = next;
    }
};

bool isPallindrome(vector<int> &ans){

    int size = ans.size();
    for(int i = 0; i < size/2; i++){
        if(ans[i] != ans[size-i-1]){
            return false;
        }
    }
    return true;
}

bool checkPallindrome(node* head){

    if(head == NULL){
        return head;
    }

    vector<int> ans;

    node* temp = head;
    while(temp != NULL){
        ans.push_back(temp->data);
        temp = temp->next;
    }

    return isPallindrome(ans);
}   

int main(){

    return 0;
}