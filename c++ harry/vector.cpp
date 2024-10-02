#include<iostream>
#include<vector>

using namespace std;

template<class t1 >
void setData(vector<t1>&vec, int size){
    int element;
    for(int i=0; i<size; i++){
        cout<<"enter the value at "<<i+1<<" : ";
        cin>>element;
        vec.push_back(element);
        // cout<<endl;
    }
}
template<class t1 >
void display(vector<t1>&v ){
    for(int i=0; i<v.size(); i++){
       cout<<" value at "<<i+1<<" : "<<v[i];
        // cin>>vec[i]; 
        cout<<endl;
    }
}
template<class t1 >
void display1(vector<t1>&v){
    vector<int> :: iterator it;
    for(it=v.begin(); it!=v.end(); it++){
       cout<<" value at "<<" : "<<*it;
        // cin>>vec[i]; 
        cout<<endl;
    }
}


int main(){

    vector<int> a;
    // int size;
    // cout<<"enter the size of vector : ";
    // cin>>size;
    // setData(a, size);
    // display(a);
    // cout<<"\n\n";

    
    // vector<int> :: iterator iter = a.end();
    // a.insert(iter, 6);
    // display1(a);
    a.push_back(100) ;

    cout<<a[0]<<endl;
    // display(a);
    return 0;
}