#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component){
    //ans store
    component.push_back(node);
    //mark visited
    visited[node] = true;

    //recursive call for every connected node
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){

    //prepare adj List
    unordered_map<int, list<int> >adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    //for all nodes, call DFS, if not visited

    for(int i = 0; i < V ; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
}
int main(){

}