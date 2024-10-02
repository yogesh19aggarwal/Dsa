#include <iostream>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class graph{
    public:
     unordered_map<T , list<T> > adj;

    void addEdge(T u , T v , bool direction){
        // direction = false/0   == undirected graph
        // direction = 1/true == directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i : adj){
            cout << i.first <<" -> ";
            for(auto j : i.second){
                cout<<j<<", ";
            }cout<<endl;
        }
    }
};

int main(){
    //  u ---- v 
    //  |      | \
    //  |      |   z
    //  |      | /
    //  a ---- b     undirected graph

    //  u ----> v
    //  ^       ^
    //  |       | \
    //  |       |   z
    //  |       | /
    //  a ----  b    directed graph

    int n;
    cout<<"enter the no. of nodes : ";
    cin>>n;

    int m;
    cout<<"enter the no. of edges : ";
    cin>>m;

    graph<int> g;

    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u , v, 0);
    }

    g.printAdjList();

    return 0;
}