#include <bits/stdc++.h>
using namespace std;
// function to return sum of elements 
// in an array of size n 
int sum(int arr[], int n) 
{ 
    int sum = 0; // initialize sum 
    // Iterate through all elements 
    // and add them to sum 
    for (int i = 0; i < n; i++) 
    sum += arr[i]; 
  
    return sum; 
} 
int main()
{ 
    int arr[] =  {45, 67, 78, 89, 90};
    int n = sizeof(arr) / sizeof(arr[0]);//5
	cout << "Sum of given array is "<< sum(arr, n)<<endl; 
    // cout<<sizeof(arr[0]);
    // cout<<sizeof(arr[1]);
    // cout<<sizeof(arr);
    return 0; 
}
