#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <list>
#include <set>

using namespace std;

template <typename T>
class graph{
    public:
     unordered_map<int , list<int> > adj;
    
    void addAdj(T u , T v , bool direction){

        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }

    void print(unordered_map<int , list<int> > adj){

        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<", ";
            }cout<<endl;
        }
    }
};

void makeGraph(vector<vector<int>> &edges , unordered_map<int, list<int> > &adjList){

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(int node , unordered_map<int , bool> &visited , unordered_map<int , list<int> > &adjList, vector<int> &component){

    component.push_back(node);

    visited[node] = 1;

    for(auto i : adjList[node]){
        if(!visited[i]){
            dfs(i , visited , adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V , int E , vector<vector<int>> &edges){ // v = vertixes &  e = edges

    unordered_map<int , list<int> > adjList;
    unordered_map<int , bool> visited;

    vector<vector<int> > ans;

    makeGraph(edges , adjList);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i , visited, adjList , component);
            ans.push_back(component);
        }
    }
    return ans;
}



int main(){
    



    return 0;
}