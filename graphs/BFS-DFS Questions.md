## BFS Questions

#### BFS
```cpp
void bfs(int node, vector<int> adj[], vector<bool>&vis, vector<int>&ans){
        queue<int> que;
        que.push(node);
        vis[node] = 1;
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            ans.push_back(u);
            
            for(auto v : adj[u]){
                if(!vis[v]){
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
        
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<int> ans;
        bfs(0, adj, vis, ans);
        return ans;
    }

```
 
1. Flood Fill(https://leetcode.com/problems/flood-fill/)
#BFS 
```cpp
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int iniColor = image[sr][sc];

        if (iniColor == color) return image;

        int m = image.size();

        int n = image[0].size();

        queue<pair<int, int>>que;

        que.push({sr, sc});

  

        vector<vector<int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};

  

        while(!que.empty()){

            int i = que.front().first;

            int j = que.front().second;

            que.pop();

  

            image[i][j] = color;

            for(int ind=0; ind<4; ind++){

                int new_i = i + directions[ind][0];

                int new_j = j + directions[ind][1];

  

                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && image[new_i][new_j] == iniColor){

                    que.push({new_i, new_j});

                }

            }

        }
        return image;

    }
```

---

2. 01 Matrix(https://leetcode.com/problems/01-matrix/)
#BFS
Given an `m x n` binary matrix `mat`, return _the distance of the nearest_ `0` _for each cell_.
The distance between two adjacent cells is `1`.
```cpp
vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        int m = grid[0].size();

        // visited and distance matrix

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<vector<int>> dist(n, vector<int>(m, 0));

        // <coordinates, steps>

        queue<pair<pair<int,int>, int>> q;

        // traverse the matrix

        for(int i = 0;i<n;i++) {

            for(int j = 0;j<m;j++) {

                // start BFS if cell contains 0

                if(grid[i][j] == 0) {

                    q.push({{i,j}, 0});

                    vis[i][j] = 1;

                }

                else {

                    // mark unvisited

                    vis[i][j] = 0;

                }

            }

        }

        int delrow[] = {-1, 0, +1, 0};

        int delcol[] = {0, +1, 0, -1};

        // traverse till queue becomes empty

        while(!q.empty()) {

            int row = q.front().first.first;

            int col = q.front().first.second;

            int steps = q.front().second;

            q.pop();

            dist[row][col] = steps;

            // for all 4 neighbours

            for(int i = 0;i<4;i++) {

                int nrow = row + delrow[i];

                int ncol = col + delcol[i];

                // check for valid unvisited cell

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m

                && vis[nrow][ncol] == 0) {

                    vis[nrow][ncol] = 1;

                    q.push({{nrow, ncol}, steps+1});  

                }

            }

        }

        // return distance matrix

        return dist;

    }
```

- Here, I use a classic BFS approach to solve the problem. I have been given a matrix "mat" with 0s and 1s and the goal is to return the distance of the nearest `0` from each cell(i.e. node). I initialize a 'dist' matrix to store the distance of the nearest `0` and a 'vis' matrix to check if a cell has been visited or not. 
- Initially, I traverse the 'mat' matrix and store the `<coordinates, steps>(<<i, j>, steps> )` in a queue. This step signifies the initial node/nodes from where I will do the BFS. Eg., If there are 3 0s in the 'mat' matrix, then all those coordinates are pushed into the queue, because we'll do our BFS from these coordinates. We also mark these visited(i.e. 1) in the 'vis' matrix. A node is only marked as visited when it has been pushed into the queue, so if a node isn't pushed into the queue, then it isn't marked as visited.
- For this question, we have 2 approaches, either we do BFS when we find a 1 to calculate the nearest 0, but that'll take much more time than doing a BFS when we find a 0, and then calculating the distance for each non-zero cell. 
- Afterwards, we declare and initialize 2 arrays, delRow and delCol, to account for the directions that we can go in from our current cell. Just like an adjacency list, where we can go to the adjacent nodes that are connected to the current node we're traversing, here, we can go to 4 different nodes that are adjacent to the current node. These 4 different nodes are `(i,j+1), (i,j-1), (i+1,j), (i-1,j)`. Just to make the code easier, we use 2 vectors to account for these directions, instead of typing each one. 
- For each set of new coordinates, i.e. a neighbor or an adjacent node, we check if it is unvisited. If it is unvisited, we mark it as visited and push the `<coordinates, steps+1>` in the queue. We increment the steps every time we push a node in the queue, as going from a cell to an unvisited cell takes a distance of 1. 
- At the end, we get the 'dist' matrix which contains the distances of the nearest 0 from each cell.


==Alternative Solution 1==:
```cpp
vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
	    int m = grid[0].size(); 
	    // visited and distance matrix
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    // <coordinates, steps>
	    queue<pair<int,int>> q; 
	    // traverse the matrix
	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            // start BFS if cell contains 0
	            if(grid[i][j] == 0) {
	                q.push({i,j}); 
	                vis[i][j] = 1; 
                    dist[i][j] = 0;
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    // traverse till queue becomes empty
	    while(!q.empty()) {
	        int row = q.front().first; 
	        int col = q.front().second; 
	        //int steps = q.front().second; 
	        q.pop(); 
	        //dist[row][col] = steps; 
	        // for all 4 neighbours
	        for(int i = 0;i<4;i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
                    dist[nrow][ncol] = 1 + dist[row][col];
	                q.push({nrow, ncol});  
	            }
	        }
	    }
	    // return distance matrix
	    return dist; 
    }
```
- Here, the difference is that instead of pushing `<coordinates, steps>` in the queue, I just push `<coordinates>` in the queue. Initially, I traverse the matrix and wherever I find `0`, I push the coordinates of those cells in the queue, and mark the 'dist' matrix for the coordinates of those cells as `0`.  And as I traverse the adjacent nodes of the current node, I just add 1 to the distance up until the current node, as going from one node to it's adjacent node takes a distance of 1. In this way, we populate the entire matrix 'dist' with distances.

==Alternative Solution 2== :
```cpp
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> directions{{0,1}, {0,-1}, {1,0}, {-1, 0}};
        queue<pair<int, int>> que;
        vector<vector<int>> result(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(mat[i][j] == 0){
                    que.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        while(!que.empty()){
            pair<int, int> u = que.front();
            que.pop();

            int i=u.first;
            int j=u.second;

            for(auto &dir : directions){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && result[new_i][new_j] == -1){
                    result[new_i][new_j] = 1 + result[i][j];
                    que.push({new_i, new_j});
                }
            }
        }
        return result;
    }
```

- Here, we don't use a `vis` matrix at all. We just use a `result` matrix and only traverse unvisited cells of the matrix, and '-1' in the `result` matrix signifies that a cell is unvisited. 
- Initially, we declare a matrix `result` and initialize every cell's value as -1. Then we update the distances in the `result` matrix of the cells whose values are `0`, and push them in the queue.
- Subsequently, we pop the top of the queue and until it's empty and do BFS on it, and update the `result` matrix accordingly. We only explore the unvisited cells, i.e. the ones having a value of -1.
---

3. Number Of Enclaves (https://leetcode.com/problems/number-of-enclaves/description/)
#Multi-Source #BFS
You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.
A **move** consists of walking from one land cell to another adjacent (**4-directionally**) land cell or walking off the boundary of the `grid`.
Return _the number of land cells in_ `grid` _for which we cannot walk off the boundary of the grid in any number of **moves**_.

```cpp
int numEnclaves(vector<vector<int>>& grid) {

        queue<pair<int, int>> que;

        int m = grid.size();

        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

  

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(i==0 || j==0 || i==m-1 || j==n-1){

                    if(grid[i][j] == 1){

                        que.push({i, j});

                        vis[i][j] = 1;

                    }

                }

            }

        }

  

        vector<vector<int>> direction{{0,1}, {0,-1}, {1,0}, {-1,0}};

  

        while(!que.empty()){

            int i=que.front().first;

            int j=que.front().second;

            que.pop();

            for(int ind=0; ind<4; ind++){

                int new_i = i + direction[ind][0];

                int new_j = j + direction[ind][1];

  

                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && vis[new_i][new_j] == 0 && grid[new_i][new_j] == 1){

                    que.push({new_i, new_j});

                    vis[new_i][new_j] = 1;

                }

            }

        }

  

        int count = 0;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(grid[i][j] == 1 && vis[i][j] == 0) count++;

            }

        }

        return count;

    }
```

---

4. Word Ladder - I (https://leetcode.com/problems/word-ladder/description/)
#BFS #Multi-Source 
```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string>st(wordList.begin(), wordList.end());

        st.erase(beginWord);

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while(!q.empty()){

            string word = q.front().first;

            int steps = q.front().second;

            q.pop();

  

            if(word == endWord) return steps;

            for(int i=0; i<word.size(); i++){

                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){

                    word[i] = ch;

                    if(st.find(word) != st.end()){

                        st.erase(word);

                        q.push({word, steps+1});

                    }

                }

                word[i] = original;

            }

        }

        return 0;

    }
```


---
---


#### DFS
```cpp
void dfs(vector<int> adj[], vector<bool> &vis, int u, vector<int>&ans){
        if(vis[u] == true) return;
        
        ans.push_back(u);
        vis[u] = true;
        for(int &v : adj[u]){
            if(!vis[v]) dfs(adj, vis, v, ans);
        }
        
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool>vis(V, false);
        dfs(adj, vis, 0, ans);
        return ans;
    }
```

## DFS Questions

1. Flood Fill(https://leetcode.com/problems/flood-fill/)
#DFS  
```cpp
class Solution {

public:

    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>&image, int color, vector<int> delRow, vector<int> delCol, int iniColor){

        // color with new color

        ans[row][col] = color;

        int n = image.size();

        int m = image[0].size();

  
        // there are exactly 4 neighbours

        for(int i=0; i<4; i++){

            int neighbourRow = row + delRow[i];

            int neighbourCol = col + delCol[i];

            // check for valid coordinate

            // then check for same initial color and unvisited pixel

            if(neighbourRow>=0 && neighbourRow<n && neighbourCol>=0 && neighbourCol<m &&

            image[neighbourRow][neighbourCol] == iniColor && ans[neighbourRow][neighbourCol] != color){

                dfs(neighbourRow, neighbourCol, ans, image, color, delRow, delCol, iniColor);

            }

        }

    }

  

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        // get initial color

        int iniColor = image[sr][sc];

        vector<vector<int>> ans = image;

        vector<int> delRow = {-1, 0, +1, 0};

        vector<int> delCol = {0, +1, 0, -1};


        dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);

        return ans;

    }

};
```

2. 