### Shortest Path in Undirected Graph

Just did a BFS, where I pushed `<node, dist>` in the queue.
```cpp
vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        vector<vector<int>> adj(n);
        vector<bool> vis(n);
        vector<int> ans(n, -1);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<pair<int, int>> que;
        que.push({src, 0});
        vis[src] = true;
        
        while(!que.empty()){
            int top = que.front().first;
            int dist = que.front().second;
            que.pop();
            ans[top] = dist;
            
            for(auto it : adj[top]){
                if(!vis[it]){
                    que.push({it, dist+1});
                    vis[it] = true;
                }
            }
        }
        
        return ans;
    }
```

---
### Shortest Path in a Directed Acyclic Graph



---
### Dijkstra's Algorithm
(https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)

- ==PseudoCode==
```
while(!pq.empty()){
	dis, node = top();

		for(iterate on adjacent nodes){
			if(conditional check){
				update dist;
				push in pq; 
			}
		}
}
```

- ==Code==
```cpp
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(V, 1e9);
        
        ans[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto vec : adj[node]){
                int adjNode = vec[0];
                int weight = vec[1];
                
                if(dist + weight < ans[adjNode]){
                    pq.push({dist+weight, adjNode});
                    ans[adjNode] = dist+weight;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
// } Driver Code Ends
```

`Time Complexity : ElogV`(refer Striver's G-34 video in Graph Series for Time Complexity Intuition and Derivation)

- ==Shortest Path using Dijkstra's Algorithm==
We use a 'parent' vector to store the parent of the current node to know how the current node was reached. Here, the solution returns the weight of the path in the 0th index, and then the path in the following indices of the 'path' vector.
```cpp
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9), parent(n+1, -1);
        
        dist[1] = 0;        // Starting node's distance is 0
        parent[1] = 1;      // Starting node's parent is itself
        pq.push({0, 1});    // Push starting node into the priority queue 
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int d = it.second;
                if(dis + d < dist[adjNode]){
                    dist[adjNode] = dis + d;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        
        vector<int> path;
        int node = n;
        
        while(node != 1){
            path.push_back(node);
            node = parent[node];
            if (node == -1) return {-1};
        }
        
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        return path;
    }
```

---
### PROBLEMS
- Shortest Path In a Binary Maze 
(https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)

Here, I used Dijkstra's algo to solve the question. Could've used a queue instead of a priority queue here, as the distance between adjacent nodes is always '1', and so we don't need to find the node with the smallest dist/edge weight, as all are '1'.

```cpp
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (n == 0 || grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

  

        pair<int, int> source(0, 0);

        pair<int, int> destination(n-1, n-1);

  

        if (source.first == destination.first &&

            source.second == destination.second)

            return 1;

  

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};

  

        vector<vector<int>> result(n, vector<int>(n, 1e9));

        result[source.first][source.second] = 0;

        pq.push({0, {source.first, source.second}});

  

        while(!pq.empty()){

            auto it = pq.top();

            pq.pop();

  

            int dist = it.first;

            int row = it.second.first;

            int col = it.second.second;

  

            for(int i=0; i<8; i++){

                int new_row = row + directions[i][0];

                int new_col = col + directions[i][1];

  

                if(new_row>=0 && new_row<n && new_col>=0 && new_col<n && grid[new_row][new_col] == 0 && dist + 1 < result[new_row][new_col]){

                    result[new_row][new_col] = 1+dist;

  

                    if (new_row == destination.first &&

                        new_col == destination.second) return (dist + 1) + 1;

                    pq.push({1 + dist, {new_row, new_col}});

  

                }

            }

        }

        return -1;

    }
```


- Path With Minimum Effort
(https://leetcode.com/problems/path-with-minimum-effort/description/)


```cpp
int minimumEffortPath(vector<vector<int>>& heights) {

        typedef pair<int, pair<int, int>> P;

        priority_queue<P, vector<P>, greater<P>> pq;

  

        int n = heights.size();

        int m = heights[0].size();

  

        vector<vector<int>> dist(n , vector<int>(m, 1e9));

        dist[0][0] = 0;

        pq.push({0, {0, 0}});

  

        vector<vector<int>> directions{{0,1}, {1,0}, {0, -1}, {-1, 0}};

  

        while(!pq.empty()){

            auto it = pq.top();

            pq.pop();

            int diff = it.first;

            int row = it.second.first;

            int col = it.second.second;

  

            if(row == n-1 && col == m-1) return diff;

  

            for(auto &i : directions){

                int newr = row + i[0];

                int newc = col + i[1];

  

                if(newr>=0 && newr<n && newc>=0 && newc<m){

                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

  

                    if(newEffort < dist[newr][newc]){

                        dist[newr][newc] = newEffort;

                        pq.push({newEffort, {newr, newc}});

                    }

                }

            }

        }

  

        return 0;

    }
```

---
- Cheapest flights within K stops
(https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)

```cpp
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [node, distance] = q.front();
                q.pop();

                if (!adj.count(node)) continue;

                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
```

---
- Number of Ways to Arrive at Destination 
(https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)
```cpp
int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e12);
        vector<int> ways(n, 0);

        dist[0]  = 0;
        ways[0] = 1;
        pq.push({0, 0});
        long long mod = 1e9+7;

        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;
            
            for(auto& it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                long long newCost = dis + edgeWt + 0LL;
                if(newCost < dist[adjNode]){
                    dist[adjNode] = newCost;
                    pq.push({newCost, adjNode});
                    ways[adjNode] = ways[node]%mod;
                }

                else if(newCost == dist[adjNode]){
                    ways[adjNode] += ways[node];
                    ways[adjNode] %= mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
```

---
### Bellmann - Ford Algorithm

Here, the algorithm is similar to Dijkstra's except the fact that we iterate over the edges for exactly N-1 times where N is the number of node or vertices. We then do the Nth relaxation(or iteration) and if it the relaxation occurs, then we conclude that graph has a negative cycle.
```cpp
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}
		return dist;
    }
```

----
## Floyd - Warshall Algorithm

Algorithm to calculate the shortest path from each node to every other node.
```cpp
void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
			}
		}
		
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}
```

---
