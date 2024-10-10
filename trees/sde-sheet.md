- Top-View
```cpp
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int line = it.second;
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            //only the top element is considered, and once one element is updated, 
            //that is part of the top view
//in case of BOTTOM-VIEW, this map keeps getting updated until the level order traversal is over
            
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};
```

- Left-View
```cpp
void solve(Node *root, vector<int> &ans, int level){
    if(root == NULL) return;
    
    if(ans.size() == level) ans.push_back(root->data);
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans;
   int level=0;
   solve(root, ans, level);
   return ans;
}
```

- Vertical Order Traversal
(when no sorting between row or col values is required)
```cpp
vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        queue<pair<TreeNode*, int>> q; //Node, column

        q.push({root, 0});

        map<int, vector<int> mpp; //column, Vector<Node->Data>

        while(!q.empty()){

            auto it = q.front();

            q.pop();

  

            TreeNode* node = it.first;

            int line = it.second;

            mpp[line].push_back(node->val);

  

            if(node->left) q.push({node->left, line-1});

            if(node->right) q.push({node->right, line+1});

        }

  

        for(auto it : mpp){

            vector<int> temp = it.second;

            sort(temp.begin(), temp.end());

            ans.push_back(temp);

        }

        return ans;

    }
```

- Vertical Order Traversal(Leetcode) :https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
```cpp
vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        queue<pair<TreeNode*, pair<int, int>>> q; //Node, column

        q.push({root, {0,0}});

        map<int, map<int, multiset<int>>> mpp; //row, column, Vector<Node->Data>

        while(!q.empty()){

            auto it = q.front();

            q.pop();

  

            TreeNode* node = it.first;

            int x = it.second.first, y = it.second.second;

            mpp[x][y].insert(node->val);

  

            if(node->left) q.push({node->left, {x-1, y+1}});

            if(node->right) q.push({node->right, {x+1, y+1}});

        }

  

        for(auto p : mpp){

            vector<int> temp;

            for(auto q : p.second){

                temp.insert(temp.end(), q.second.begin(), q.second.end());

            }

  

            ans.push_back(temp);            

        }

        return ans;

    }
```

- PreOrder, Inorder, PostOrder Traversals in One Go
```cpp
vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;
    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }
    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;
    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});
    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        // this is part of pre
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2
            // (inorder) for this node
            it.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(it); 
            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        // this is a part of in
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3
            // (postorder) for this node
            it.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(it); 
            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        // this is part of post
        else {
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->data);
        }
    }
    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
```

- Print all root to node paths
```cpp
class Solution {
    private:
        void solve(Node* root, vector<int>&currentPath, vector<vector<int>>&ans){
            if(root == NULL) return;
            
            currentPath.push_back(root->data);
            
            solve(root->left, currentPath, ans);
            solve(root->right, currentPath, ans);
            
            if(root->left == NULL && root->right == NULL) ans.push_back(currentPath);
            currentPath.pop_back();
        }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> currentPath;
        solve(root, currentPath, ans);
        return ans;
    }
};
```

- Max Width of Binary Tree
```cpp
int widthOfBinaryTree(TreeNode* root) {
        typedef unsigned long long ll;

        ll maxWidth=0;

        queue<pair<TreeNode*, ll>> q;

        q.push({root, 0});

        while(!q.empty()){

            ll l = q.front().second;

            ll r = q.back().second;
            
            maxWidth = max(maxWidth, r-l+1);

            int n = q.size();

            while(n--){

                TreeNode* curr = q.front().first;

                ll idx = q.front().second;

                q.pop();

  

                if(curr->left) q.push({curr->left, 2*idx+1});

                if(curr->right) q.push({curr->right, 2*idx+2});

            }

        }

        return maxWidth;

    }
```

- Max Depth Of Binary Tree
```cpp
int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            int height = 1 + max(left, right);
            return height;
    }
```

OR

```cpp
class Solution {
    private:
        int solve(TreeNode* root){
            if(root == NULL) return 0;
            return 1+max(solve(root->left),solve(root->right));
        }
public:
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};
```

- LCA of a Binary Tree
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else{
            return root;
        }
    }
```



