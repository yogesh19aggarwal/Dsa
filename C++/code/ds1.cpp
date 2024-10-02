#include<iostream>
#include<conio.h>
using namespace std;
// int a=6;
int main(){
	int c, first, last, middle, n, search, array[100];
	n = 15;
	int a[15] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150};
	
	cout<<"Enter value to search :";
	cin>>search;
	first = 0;
	last = n-1;
	middle = (first+last)/2 + 1;
	
	while (first <= last){
		if(array[middle] < search)
		  first = middle-1;
		else if(a[middle] == search){
			cout<<"\n found at location :"<< middle+1;
			break;
		}  
		else{
			last = middle+1;
			middle = (first + last)/2;
		}
		if(first > last)
		  cout<<"not found! ";
		else
		  cout<<first;  


		//   int a=7;
		//   cout<<::a;
		return 0;  
	}
}
