#include<iostream>

using namespace std;

class stack{

    int size;
    int *arr;
    int top1;
    int top2;
 
 public:
    stack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int ele){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = ele;
            return;
        }
    }

    void push2(int ele){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = ele;
            return;
        }
    }

    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }else{
            return -1;
        }
    }

    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }else{
            return -1;
        }
    }
};

int main(){
    
    return 0;
}