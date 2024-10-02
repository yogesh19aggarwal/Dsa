#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void printVec(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}
// printing a nesting of pair in vector
void printVecPair(vector<pair<int , int>> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i].first<<", "<<v[i].second<<endl;
    }cout<<endl;
}

int main(){

    // **PAIRS : it is only for describing the relation b/w two or storing the values which are related to each other

        // declaration
            // pair<int , string> p;

        // input
            // p = make_pair(2 , "abc");
            // p = {2 , "abc"};

        // output
            // cout<<p.first<<", "<<p.second<<endl;

        // initialisation of array of pairs
            // pair<int , int> p1[3];
            // p1[0] = {1,2};
            // p1[1] = {2,3};
            // p1[2] = {3,4};
        
        // output of array
            // for(int i = 0; i < 3; i++){
            //     cout<<p1[i].first<<", "<<p1[i].second<<endl;
            // }

    // **VECTORS

        // initialisation
            // vector<int> v; //it has variable size. you can store element upto your pc memory

            // input
            // int n;
            // cin>>n;
            // for(int i = 0; i < v.size(); i++){
            //     int x;
            //     cin>>x;
            //     v.push_back(x);
            // }

    // **NESTING IN VECTORS

        // *VECTOR OF PAIR
        //    vector<pair<int , int>>v;
    
    // **Iterators
        // vector<int> v = {2,3,5,6,7};
        // for(int i=0; i< v.size(); i++){
        //     cout<< v[i] << " ";
        // }
        // cout<<endl;

        // initialisatin of iterator
            // vector<int> :: iterator it = v.begin();
            // cout<< (*it+1) <<endl;
        
        // iterate through iterator
            // for(it = v.begin(); it != v.end(); it++){
                // cout<< (*it) <<" ";
            // }
        
        // in case of nestingS
            // vector<pair<int , int>> v_p = {{1,2} , {2,3}, {3,4}};

            // vector<pair<int, int>> :: iterator it;
            // for(it = v_p.begin(); it != v_p.end(); it++){
            //     cout<< (*it).first <<" "<< (*it).second<<endl;
            // }
            // cout<<endl;
            ////we can also write this in the form
                // for(it = v_p.begin(); it != v_p.end(); it++){
                //     cout<< (it->first) <<" "<< (it->second)<<endl;
                // }cout<<endl;
        // short iterator

            // without auto
                // for(int value : v){
                //     cout << value << " ";
                // }cout<<endl;

            // with auto : auto keyword can be used anywhere it automatically assumes the type of data type
                // for(auto it1 : v_p){
                //     cout<<it1.first<<" "<<it1.second<<endl;
                // }
    // **Maps
        // Maps helps to create mapping of two objects. It stores the value in sorted order according to key(first value of map). but in unorderd map it stores in the order in which user puts input.
        // ordered maps use red black trees to implement

        // Initialisation
            map<int , int> m;

            // input value
            m[1] = 1;
            m[5] = 1;  //O(log(n)) time complexity for inserting element in map
            m[3] = 1;
            m.insert({4 , 2});
            m[1]++;

            cout<<m[1]<<endl;
            for(auto i : m){
                cout<<i.first<<" "<<i.second<<endl;
            }
            
           
    return 0;
}