#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class graph{
    unordered_map<int , list<int> > adjlist;

    void addAdj(int u, int v, bool direction){

        adjList[u].push_back(v);
        if(!direction){
            adjList[v].push_back(u);
        }
    }
};
void printAdj(unordered_map<int , list<int> > &adj){

    for(auto i : adj){
        cout<<i.first<<"->";
        for(auto j : i.second){
            cout<<j<<", ";
        }cout<<endl;
    }
}

void vecToMap(vector<vector<int>> &adj , unordered_map<int , list<int> > &adjList){
    
    for(int i = 0; i < adj.size(); i++){
        int u = adj[i][0];
        int v = adj[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// ******1. detect cycle********* 


//      undirected graph

//           using bfs

bool isCycleBFS(int src , unordered_map<int , bool> &visited , unordered_map<int , list<int> > adjList){

    unordered_map<int , int> parent;

    parent[src] = -1;
    visited[src] = 1;

    queue<int> q;

    q.push(src);
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adjList[frontNode]){
            if(visited[frontNode] == true && neighbour != parent[frontNode]){
                return true;
            }
            else if(!visited[frontNode]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}   

string cycleDetection(vector<vector<int> > &edges , int n, int m){

    unordered_map<int , list<int> > adjList;
    vecToMap(edges , adjList);

    unordered_map<int , bool> visited;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = isCycleBFS(i , visited , adjList);
            if(ans == 1){
                return "YES";
            }
        }
    }
    return "NO";
}

//           using dfs

bool isCyclicDFS(unordered_map<int , list<int> > &adjList, unordered_map<int , bool> &visited, int src, int parent){

    visited[src] = 1;

    for(auto neighbour : adjList[src]){
        if(!visited[neighbour]){
            bool cycle = isCyclicDFS(adjList , visited, neighbour , src);
            if(cycle){
                return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

string checkCycle(vector<vector<int> > &edges , int n , int m){
    unordered_map<int , list<int> > adjList;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int , bool> visited;

    for(int i =0; i < n; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(adjList , visited , i , -1);
        }
    }
}

//       directed graph

// using dfs

bool checkDFS(int node , unordered_map<int, bool> &visited, unordered_map<int, bool> dfsVisited, unordered_map<int, list<int>> &adjList){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkDFS(neighbour, visited, dfsVisited, adjList);
            if(cycleDetected){
                return true;
            }

        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectInDirectedGraph(int n, vector<pair <int, int>> &edges){

    // create adjacency list
    unordered_map<int , list<int> > adjList;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    // call dfs for all component
    unordered_map<int, bool> visited;
    unordered_map<int , bool> dfsVisited;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bool cycle = checkDFS(i, visited , dfsVisited, adjList);
            if(cycle){
                return true;
            }
        }
    }

    return false;
}


//  ********2. Topological sort**********
// 
// using dfs



int main(){

    return 0;
}