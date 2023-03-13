#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra (vector<vector<int>> &vec, int vertices, int edges, int source){
    //create adjacencylist
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<vertices; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    //creation of distance array with infinite value initially
    vector<int> dist(vertices);
    for(int i = 0; i < edges; i++)
        dist[i] = INT_MAX;

    //creation of set on basis (distance, node)
    set<pair<int, int>> st;

    //initialise distance  and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        //fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record now
        st.erase(st.begin());

        //traverse on neighbours 
        for(auto neighbour: adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){

                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                //if record found, then erase it
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update 
                dist[neighbour.first] = nodeDistance + neighbour.second;

                //record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first)); 
            }
        }
    }
    

}

int main(){

}

//TimeComplexity = O(ElogV)
//SpaceComplexity = O(N + E)