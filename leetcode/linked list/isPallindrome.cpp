#include<iostream>
#include<vector>

using namespace std;

class node{

 public:
    int data;
    node* next;

    node(){
        this->data = -1;
        next = NULL;
    }
    node(int val){
        data = val;
        next = NULL;
    }
    node(int val, node* next){
        this->data = val;
        this->next = next;
    }
};

bool checkPallindrome(vector<int> arr){
    int low = 0;
    int high = arr.size()-1;

    while(low < high){
        if(arr[low++] != arr[high--]){
            return false;
        }
    }
    return true;
}

bool isPallindrome(node* head){

    if( head == NULL){
        return head;
    }

    vector<int> ans;

    node* temp = head;

    while(temp != NULL){
        ans.push_back(temp->data);
        temp = temp->next;
    }
    return checkPallindrome(ans);
}

int main(){

    return 0;
}