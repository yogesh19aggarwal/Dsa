#include<iostream>
#include<queue>
using namespace std;

void reverseString(string str){ // for just printing does not change the srting input
    char ch = str[0]; 
    if(ch == '\0'){
        return ;
    }
    reverseString(str.substr(1));
    cout<<ch;
}

void reversestring(string &str , int i){ // does changes in actual string
    int n = str.size();

    if(i == n/2){
        return;
    }
    swap(str[i] , str[n - i - 1]);
    // i++;

    reversestring(str , i+1);
}

bool checkPalindrome(string &str , int i){

    int n = str.size();
    if(i == n/2){
        return true;
    }
    
    if(str[i] != str[n-i-1]){
        return false;
    }
    
    return checkPalindrome(str , i+1);
}

long long int power(int a , int b){ // we have to find a^b

    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    long long int ans = power(a , b/2);
    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}

void sortArrayB(int *arr , int size){

    // base case
    if(size == 0 || size == 1){
        return;
    }

    for(int i = 0; i < size; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
    }
    sortArrayB(arr , size-1);
}

void merge(int *arr , int low , int mid , int end){

    int i = low; 
    int j = mid+1;
    int k = low;

    int arr1[end+1];

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            arr1[k] = arr[i];
            i++; k++;
        }
        else{
            arr1[k] = arr[j];
            j++;k++;
        }
    }
    while(i <= mid){
        arr1[k] = arr[i];
        i++; k++;
    }
    while(j <= end){
        arr1[k] = arr[j];
        j++; k++;
    }

    for(int i = low; i <= end; i++){
        arr[i] = arr1[i];
    }
}
void mergeSort(int *arr, int low, int high) {
    // cout<<"hi"<<" ";
    if(low >= high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr , mid+1, high);
    merge(arr , low , mid , high);
}

// heap
int kthsmallest(int arr[] , int size , int k){

    priority_queue<int> pq;

    for(int i =0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i = k; i <= size; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main(){

    // string str = "yogesh";
    // string str1 = "aabbccbbaa";
    // // reversestring(str , 0 );
    // if(checkPalindrome(str1 , 0)){
    //     cout<<"true";
    // }
    // else{
    //     cout<<"false";
    // }

    // int a = 2 , b = 62;
    // long long int ans =  power(a , b);
    // cout<<ans;

    int arr[] = {3,6,9,2,1,4};
    mergeSort(arr, 0 , 5);

    for(int i = 0; i < 6; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;



    return 0;
}