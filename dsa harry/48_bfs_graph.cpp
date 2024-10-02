#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;


void prepareAdjList(unordered_map <int , list<int> > &adjList , vector<pair<int , int>> &adj){

    for(int i = 0; i < adj.size(); i++){
        int u = adj[i].first;
        int v = adj[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map <int , list<int> > &adjList , unordered_map<int , bool> &visited , vector<int> &ans , int node){
    
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(vector<pair<int , int> > adj , int vertex){

    unordered_map<int , list<int> > adjList;
    vector<int> ans;
    unordered_map<int , bool> visited;

    prepareAdjList(adjList , adj);

    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            bfs(adjList , visited , ans , i);
        }
    }

}

int main(){

    
    return 0;
}