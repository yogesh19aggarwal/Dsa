#include<iostream>
#include<algorithm>

using namespace std;

int countTriplets(int arr[], int n){

    sort(arr, arr+n);
    int count = 0;

    for(int i = n-1; i >= 2; --i){

        int great = arr[i];
        int low = 0;
        int high = i - 1;

        while(low < high){

	        if(arr[low] + arr[high] == great){
	            count++;
	            low++; high--;
	        }
	        else if(arr[low] + arr[high] > great){
	            high--;
	        }
	        else{
	            low++;
	        }
        }
    }
    return count;
}

int main(){

    
    return 0;
}