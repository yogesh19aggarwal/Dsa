#include<iostream>
#include<list>

using namespace std;

template<class t1>
void setData( list<t1> &lst, int size){
    int element;
    for(int i=0; i<size; i++){
        cout<<"enter the value at "<<i+1<<" : ";
        cin>>element;
        lst.push_back(element);
    }
}

// in list we cant use template to display because it uses iterator which doesnot support template
// template<class t2>
void display(list<int> &lst){
    list<int> :: iterator it;
    for(it = lst.begin(); it!=lst.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> lst;
    int size;
    cout<<"enter the size of list : ";
    cin>>size;

    setData(lst, size);
    // display(lst);
    lst.sort();

    list<int> lst1;
    setData(lst1, size);
    lst1.sort();
   
    display(lst);

    lst.merge(lst1);
    display(lst);

    return 0;
}