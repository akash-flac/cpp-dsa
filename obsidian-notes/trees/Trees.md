# Binary Tree Representation in C++

```cpp
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;	
	}
}

main(){
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(5);
}
```

# Traversal Techniques

```
        1
       / \
      2   3
     / \   \
    4   5   6

```

### DFS Techniques
#### Inorder Traversal (Left Root Right)
4, 2, 5, 1, 3, 6

##### Recursive
```cpp
class Solution {
    private:
        void inOrder(TreeNode* root, vector<int> &ans){
            if(root == NULL) return;
            
            inOrder(root->left, ans);
            ans.push_back(root->val);
            inOrder(root->right, ans);
        }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};
```

##### Iterative
```cpp
vector<int> inorderTraversal(TreeNode* root) {
        //iterative solution
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
```


#### Pre-order Traversal(Root Left Right)
1, 2, 4, 5, 3, 6

##### Recursive
```cpp
class Solution {
//recursive
     private: 
        void preOrder(TreeNode* root, vector<int> &ans){
            if(root == NULL) return;
            
            ans.push_back(root->val);
            preOrder(root->left, ans);
            preOrder(root->right, ans);
        }
public:
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
};
```

##### Iterative
```cpp
vector<int> preorderTraversal(TreeNode* root) {
        //iterative soln
        vector<int> preorder;
        if(root == NULL) return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right != NULL) st.push(root->right);
            if(root->left != NULL) st.push(root->left);
        }
        return preorder;
    }
```


#### Post-Order Traversal(Left Root Right)
4, 5, 2, 6, 3, 1

##### Recursive
```cpp
class Solution {
    private:
        void postOrder(TreeNode* root, vector<int> &ans){
            if(root == NULL) return;
            
            postOrder(root->left, ans);
            postOrder(root->right, ans);
            ans.push_back(root->val);
        }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};
```

##### Iterative 
- Using 2 stacks
```cpp
vector<int> postorderTraversal(TreeNode* root) {
        //iterative solution
        vector<int>ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL) st1.push(root->left);
            if(root->right != NULL) st1.push(root->right);
        }
        
        while(!st2.empty()){
            root = st2.top();
            st2.pop();
            ans.push_back(root->val);
        }
        
        return ans;
    }
```

- using 1 stack
```cpp
vector<int> postorderTraversal(TreeNode* root) {
        //iterative solution using 1 stack
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
```


### BFS Techniques
#### Level-order Traversal
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);             
                }
                ans.push_back(level);
        }
        return ans;
    }
```


