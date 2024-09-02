https://medium.com/basecxs/a-gentle-introduction-to-graph-theory-77969829ead8

Graphs -  Directed or Undirected

### Graph Representation
1. Adjacency Matrix
	1. `vector<vector<int>>adj(V+1, 0);`
	2. T.C. - O(V+E)
2. Adjacency List
	1. `unordered_map<int, vector<int>>adj;`
	2. T.C. - O(V^2)

### Graph Traversal
1. DFS(Depth First Search)
	 ```cpp
	 void dfs(adj, int u, vis){
	 if(vis[u]) == true)return;
	 vis[u] = true;
	 for(int &v : adj[u]){
		 if(!vis[v]){
		 dfs(adj, v, vis);
		 }
	 }
	 }
	```
	
2. BFS(Breadth First Search)
	 ```cpp
	 void bfs(adj, bfs, vis, int node){
        queue<int>q;
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
             }
         }
	 ```


### Cycle Detection in a Graph

- Cycle Detection in an Undirected Graph
	- Using DFS
	 ```cpp
	 dfs(adj, u, vis, parent){
	 vis[u] = true;
	for(int &v : adj[u]){
	 if(v==parent) continue;
	 if(visited[v] == true) return true;
	 if(dfs(adj, u, vis, parent) == true) return true;
	 }
	return false;
	}
```
![[Pasted image 20240701180119.png]]

- Using BFS

  ![[Pasted image 20240702115449.png]]
  

- Cycle Detection in a Directed Graph
	- Using DFS
	```cpp
	
	bool dfs(vector<int> adj[], int u, vector<bool>&vis, vector<bool>&inRecursion){
        vis[u] = true;
        inRecursion[u] = true;
        
        for(int &v : adj[u]){
            //if not visited, then we check for cycle in dfs
            if(vis[v] == false && dfs(adj, v, vis, inRecursion)) return true;
            else if(inRecursion[v] == true) return true;
        
        }
        
        inRecursion[u] = false;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<bool> inRecursion(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i] && dfs(adj, i, vis, inRecursion)) return true;
        }
        return false;
    }
	
	```

- Using BFS(Using Topological Sorting)
```cpp

bool isCyclic(int N, vector<int> adj[]) {
        queue<int> que;
	    vector<int> inDegree(N, 0);
	    
	    // 1. Filling vector with the inDegrees of all vertices
	    for(int u=0; u<N; u++){
	        for(int &v : adj[u]){
	            inDegree[v]++;
	        }
	    }
	    
	    int count = 0;
	    
	    // 2. Pushing vertices with indegree 0 into queue
	    for(int i=0; i<N; i++){
	        if(inDegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
	    
	    
	    // 3. BFS
	    vector<int> result;
	    while(!que.empty()){
	        int u = que.front();
	        result.push_back(u);
	        que.pop();
	        
	        for(int &v : adj[u]){
	            inDegree[v]--;
	            
	            if(inDegree[v] == 0){
	                que.push(v);
	                count++;
	            }
	        }
	    }
	    
	    if(count == N) {
	        return false;
	    }
	    
	    return true;
    }
```
- Topological Sorting
	- Using DFS 
	![[Pasted image 20240702194753.png]]
	
	- Using BFS(Kahn's Algorithm)
	![[Pasted image 20240702190155.png]]
	
- DSU
	- By Union
	- By Path
	

https://leetcode.com/problems/number-of-provinces/description/
https://leetcode.com/problems/course-schedule/description/
https://leetcode.com/problems/course-schedule-ii/description/
https://leetcode.com/problems/is-graph-bipartite/description/



## Shortest Path Algorithms
### Dijkstra's Algorithm
- Using Priority Queue
![[Pasted image 20240706172848.png]]

- Using Set 
![[Pasted image 20240706175823.png]]


