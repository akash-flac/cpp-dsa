1. Number of Provinces
https://leetcode.com/problems/number-of-provinces/description/

Here, we just have to find the count of the components of the graph.
![[Pasted image 20240703002258.png]]

![[Pasted image 20240703004450.png]]

2. Course Schedule I
https://leetcode.com/problems/course-schedule/description/
If cycle is present, return false. Else, return true.
```cpp

 //cycle detection using bfs(topological sort check, i.e. kahn's algorithhm)
    bool isCycle(unordered_map<int, vector<int>> &adj, vector<int>&inDegree, int n){
        queue<int> que;
        int count = 0;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                count++;
                que.push(i);
            } 
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v : adj[u]){
                
                inDegree[v]--;

                if(inDegree[v] == 0){
                    count++;
                    que.push(v);
                }
            }
        }
        
        if(count == n) return true;

        return false;       

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>inDegree(n, 0);
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        return isCycle(adj, inDegree, n);
```

3. Course Schedule II
https://leetcode.com/problems/course-schedule-ii/

Here, we have to return the vertices after being topological sorted.
```cpp

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<int>inDegree(n, 0);

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<prerequisites.size(); i++){

            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

            inDegree[prerequisites[i][0]]++;

        }

        //topological sort

        queue<int> que;

        vector<int> ans;

        int count = 0;

        for(int i=0; i<n; i++){

            if(inDegree[i] == 0){

                que.push(i);

                count++;

            }

        }

  

        while(!que.empty()){

            int u = que.front();

            que.pop();

            ans.push_back(u);

            for(int &v : adj[u]){

                inDegree[v]--;

  

                if(inDegree[v] == 0){

                    que.push(v);

                    count++;

                }

            }

        }

  

        if(count != n){

            ans.clear();

            return ans;

        }

        return ans;

    }
```

4. Find Eventual Safe States
https://leetcode.com/problems/find-eventual-safe-states/description/

- ==USING CYCLE DETECTION==

![[Pasted image 20240705172853.png]]
- *Explanation of Variables and Logic*

1. **Graph Representation (`g`)**: The graph is represented as an adjacency list, where `g[i]` contains all nodes that can be reached directly from node `i`.
2. **Color Vector (`colour`)**:
    - `0`: Unvisited node.
    - `1`: Node is being visited (in the current DFS path).
    - `2`: Node is fully processed (safe, no cycles reachable from this node).
3. **DFS (`dfs`)**:
    - Marks the node as being visited.
    - Checks all its neighbors:
        - If a neighbor is unvisited and leads to a cycle (via DFS), or if a neighbor is in the current path, a cycle is detected, and the function returns `true`.
    - If no cycles are found, the node is marked as fully processed and `false` is returned.
4. **Eventual Safe Nodes (`eventualSafeNodes`)**:
    - Iterates over all nodes.
    - If a node is fully processed or does not lead to a cycle, it is added to the result list.

- *How It Works*

- The algorithm uses DFS to detect cycles. Nodes that are part of a cycle or can reach a cycle are not safe.
- It colors nodes to keep track of their state: unvisited, visiting, or fully processed.
- If a node and its reachable nodes do not form a cycle, it is considered safe.

By the end of the process, `eventualSafeNodes` returns a list of nodes that are safe, meaning they do not lead to any cycles when starting from them.

- ==USING TOPOLOGICAL SORT==
![[Pasted image 20240705174923.png]]

- *Explanation*
1. **Reverse the Graph**: Reverse all the edges in the graph.
2. **Calculate In-degrees**: Calculate the in-degree for each node in the reversed graph.
3. **Topological Sort Using Kahn's Algorithm**: Perform a topological sort using a queue to keep track of nodes with zero in-degree. These nodes are "safe" nodes because they do not have any outgoing edges in the reversed graph.

