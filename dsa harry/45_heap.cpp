#include <bits/stdc++.h>

using namespace std;

class maxHeap{
    public:
        int arr[101];
        int size;

        maxHeap(){
            arr[0] = -1;
            size = 0;
        }

    void insert(int val){
        size = size + 1;
        int index  = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[index] > arr[parent]){
                swap(arr[index] , arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    } 

    void Delete(){

        if(size == 0){
            cout<<"no element to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[leftIndex] > arr[i]){
                swap(arr[leftIndex] , arr[i]);

                i = leftIndex;
            }
            else if(rightIndex < size && arr[rightIndex] > arr[i]){
                swap(arr[rightIndex] , arr[i]);

                i = rightIndex;
            }
            else{
                return;
            }
        }
    }

    void display(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

void heapify(int arr[], int size, int ele){

    int largest = ele;

    int left = 2*ele;
    int right = 2*ele + 1;

    if(left <= size && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= size && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != ele){
        swap(arr[largest] , arr[ele]);
        heapify(arr , size , largest);
    }
}

void heapSort(int arr[] , int size){
    int t = size;

    while(t > 1){
        // step 1 : swap root with last 
        swap(arr[t] ,  arr[1]); 
        t--;

        // step 2
        heapify(arr , t , 1);
    }
}

int main(){

    // maxHeap h;
    // h.insert(50);
    // h.insert(53);
    // h.insert(55);
    // h.insert(52);
    // h.insert(54);

    // h.display();

    // h.Delete();

    // h.display();

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    // for(int i = n/2; i > 0; i--){
    //     heapify(arr , n , i);
    // }
    // cout<<"printing the array now"<<endl;

    // for(int i = 1; i <= n; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    // heapsort
    heapSort(arr , n);

    cout<<"printing sorted array"<<endl;

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    cout<<"using Priority Queue"<<endl;
    // stl for heap

    priority_queue<int> pq;
    // it is default max heap

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"element at top : "<<pq.top()<<endl;

    // min heap

    priority_queue<int , vector<int> , greater<int> > minheap;
    // now if you push a element in this it will store like min heap

    return 0;
}