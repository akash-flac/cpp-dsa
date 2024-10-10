Recursion means "defining a problem in terms of itself". This can be a very powerful tool in writing algorithms. Recursion comes directly from Mathematics, where there are many examples of expressions written in terms of themselves. For example, the Fibonacci sequence is defined as: 
F(i) = F(i-1) + F(i-2).

Recursion is the process of defining a problem (or the solution to a problem) in terms of (a simpler version of) itself.

![](attachments/Pasted%20image%2020240618172215.png)

Simple ways to build a recursive solution:
- Deciding the base case, i.e. the output for the simplest possible input/set of inputs
- Playing around with some other cases(inputs and their outputs), and maybe visualizing
- Relating harder cases to the simpler ones
- Generalize the pattern(write a recurrence relation in terms of 'n' input)(e.g. f(n) = f(n-1) + f(n-2))
---
#### ==//chatgpt==
#### Q) How to tell if a problem is recursive?
To determine if a problem is suitable for a recursive solution, you can look for certain characteristics and patterns in the problem. Here are some key indicators that a problem might be well-suited for recursion:

### Indicators of a Recursive Problem

1. **Self-Similar Subproblems:**
   - The problem can be broken down into smaller instances of the same problem.
   - Example: Finding the factorial of a number (`n! = n * (n-1)!`).

2. **Overlapping Subproblems:**
   - The problem involves solving the same subproblems multiple times.
   - Example: Computing Fibonacci numbers where `F(n) = F(n-1) + F(n-2)` involves solving `F(n-1)` and `F(n-2)`.

3. **Divide and Conquer:**
   - The problem can be divided into independent subproblems, solved separately, and then combined to form the solution.
   - Example: Merge Sort where the array is divided into two halves, sorted separately, and then merged.

4. **Natural Base Case:**
   - There is a simple condition under which the problem can be solved directly without further recursion.
   - Example: In the factorial problem, `0! = 1` is the base case.

5. **Tree-Like Structure:**
   - The problem involves exploring multiple branches or choices, often modeled as a tree.
   - Example: Traversing a binary tree or exploring all combinations/permutations.

6. **Backtracking Problems:**
   - The problem involves trying multiple possible solutions and backtracking upon failure.
   - Example: Solving a maze, N-Queens problem, or Sudoku.

### Examples of Recursive Problems

#### 1. Factorial Calculation
```cpp
int factorial(int n) {
    if (n == 0) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}
```

#### 2. Fibonacci Sequence
```cpp
int fibonacci(int n) {
    if (n <= 1) return n; // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}
```

#### 3. Binary Tree Traversal (Inorder)
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return; // Base case
    inorderTraversal(root->left); // Traverse left subtree
    cout << root->val << " "; // Visit node
    inorderTraversal(root->right); // Traverse right subtree
}
```

### Steps to Identify Recursive Solutions

1. **Identify the Base Case:**
   - Find the simplest instance of the problem that can be solved directly.

2. **Identify the Recursive Case:**
   - Determine how the problem can be broken down into smaller subproblems of the same type.

3. **Ensure Subproblems Converge to the Base Case:**
   - Make sure each recursive call brings the problem closer to the base case.

4. **Combine Subproblem Solutions:**
   - Figure out how to combine the results of subproblems to form the solution to the original problem.

### Example Analysis: Sum of an Array

#### Problem: Compute the sum of elements in an array.

1. **Base Case:**
   - An array with no elements has a sum of 0.

2. **Recursive Case:**
   - The sum of an array is the first element plus the sum of the remaining elements.

#### Recursive Solution:
```cpp
int sumArray(const vector<int>& arr, int n) {
    if (n <= 0) return 0; // Base case
    return arr[n - 1] + sumArray(arr, n - 1); // Recursive case
}
```

### Conclusion

By looking for self-similar subproblems, natural base cases, and tree-like structures, you can often identify problems that are suitable for recursive solutions. Understanding these patterns helps you recognize when recursion is an appropriate and efficient method to solve a problem.

--- 
#### Q) Does using recursion lead to more space and time efficiency?
Recursion can lead to both time and space inefficiencies, depending on the nature of the problem and how the recursion is implemented. Let's explore the potential inefficiencies and how they can be mitigated.

### Time Inefficiency

1. **Repeated Computation:**
   - Some recursive algorithms, like the naive implementation of the Fibonacci sequence, compute the same values multiple times, leading to exponential time complexity.
   ```cpp
   int fibonacci(int n) {
       if (n <= 1) return n;
       return fibonacci(n - 1) + fibonacci(n - 2);
   }
   ```
   In this case, `fibonacci(n)` calls `fibonacci(n-1)` and `fibonacci(n-2)`, and each of these calls further calls other Fibonacci computations, resulting in many repeated calculations.

2. **Mitigation with Memoization:**
   - Memoization stores the results of expensive function calls and reuses them when the same inputs occur again, converting the exponential time complexity to linear.
   ```cpp
   int fibonacci(int n, vector<int>& memo) {
       if (n <= 1) return n;
       if (memo[n] != -1) return memo[n];
       memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
       return memo[n];
   }
   
   int fibonacci(int n) {
       vector<int> memo(n + 1, -1);
       return fibonacci(n, memo);
   }
   ```

### Space Inefficiency

1. **Call Stack Usage:**
   - Each recursive call adds a new frame to the call stack, consuming memory. Deep recursion can lead to significant space usage or even a stack overflow.
   ```cpp
   void recursiveFunction(int n) {
       if (n == 0) return;
       recursiveFunction(n - 1);
   }
   ```

2. **Mitigation with Tail Recursion:**
   - If the recursive function is tail-recursive (the recursive call is the last operation in the function), some languages and compilers optimize it to reuse the current function’s stack frame, reducing space usage.
   ```cpp
   void tailRecursiveFunction(int n) {
       if (n == 0) return;
       // Tail call optimization can be applied here
       tailRecursiveFunction(n - 1);
   }
   ```
   However, C++ does not guarantee tail call optimization, unlike some other languages such as Scheme or Haskell.

### Examples of Recursive vs. Iterative Solutions

#### Factorial Calculation

- **Recursive Implementation:**
  ```cpp
  int factorial(int n) {
      if (n <= 1) return 1;
      return n * factorial(n - 1);
  }
  ```
  Space complexity is O(n) due to the call stack.

- **Iterative Implementation:**
  ```cpp
  int factorial(int n) {
      int result = 1;
      for (int i = 2; i <= n; ++i) {
          result *= i;
      }
      return result;
  }
  ```
  Space complexity is O(1), as it only uses a fixed amount of extra space.

### When to Use Recursion

Despite potential inefficiencies, recursion is a powerful tool and can be the best choice in certain scenarios:

1. **Natural Fit for Problem Structure:**
   - Problems like tree traversals (e.g., binary trees) and divide-and-conquer algorithms (e.g., QuickSort, MergeSort) naturally lend themselves to recursive solutions.

2. **Clarity and Simplicity:**
   - Recursive solutions can be more readable and easier to implement for problems that have a natural recursive structure.

### Conclusion

While recursion can lead to time and space inefficiencies, these can often be mitigated with techniques like memoization and, in some cases, tail call optimization. The choice between recursive and iterative solutions should be guided by the specific problem at hand, considering factors such as clarity, simplicity, and performance requirements.

--- 
#### Q) Recursion vs Backtracking
Recursion and backtracking are closely related concepts in computer science, especially in the context of solving problems involving search and optimization. Here’s an explanation of both concepts and their differences:

### Recursion

**Definition:**
- Recursion is a technique in which a function calls itself directly or indirectly in order to solve a problem.
- A recursive function typically has two main components: the base case(s) and the recursive case(s).

**Characteristics:**
- **Base Case:** The condition under which the recursion stops. This prevents infinite recursion and often represents the simplest, smallest instance of the problem.
- **Recursive Case:** The part of the function where the function calls itself with modified parameters to break the problem down into smaller subproblems.

**Example:**
A classic example of a recursive function is the calculation of the factorial of a number:

```cpp
int factorial(int n) {
    if (n == 0) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}
```

### Backtracking

**Definition:**
- Backtracking is a refinement of recursion where a recursive algorithm attempts to solve a problem incrementally by trying to build a solution piece by piece, removing those solutions that fail to satisfy the problem constraints at any point in time (hence, "backtrack").
- It’s commonly used for solving combinatorial problems like puzzles, game solving, and constraint satisfaction problems (e.g., Sudoku, N-Queens).

**Characteristics:**
- **Partial Solution:** During the search, partial solutions are built one step at a time.
- **Constraint Checking:** At each step, the algorithm checks whether the current partial solution can be extended to a complete valid solution.
- **Backtrack:** If the current partial solution cannot lead to a valid solution, the algorithm undoes the last step (backtracks) and tries a different option.

**Example:**
The N-Queens problem is a typical example of backtracking. Here’s a simplified version to place N queens on an N×N chessboard such that no two queens threaten each other:

```cpp
bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; ++i) 
        if (board[row][i]) return false;
    
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) 
        if (board[i][j]) return false;
    
    for (int i = row, j = col; j >= 0 && i < board.size(); ++i, --j) 
        if (board[i][j]) return false;
    
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col) {
    if (col >= board.size()) return true; // All queens are placed
    
    for (int i = 0; i < board.size(); ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen
            if (solveNQueens(board, col + 1)) return true; // Recur to place rest
            board[i][col] = 0; // Backtrack if placing queen at board[i][col] doesn't lead to a solution
        }
    }
    return false;
}

void printSolution(vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    int N = 4;
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    if (solveNQueens(board, 0)) {
        printSolution(board);
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}
```

### Differences Between Recursion and Backtracking

- **Purpose:**
  - **Recursion:** A general approach to solving problems by breaking them into smaller, similar subproblems.
  - **Backtracking:** A specific kind of recursion used for finding all (or some) solutions to problems by exploring all potential options and eliminating those that fail to meet the constraints.

- **Problem Type:**
  - **Recursion:** Suitable for problems where the solution involves repeated subproblems like mathematical sequences (e.g., Fibonacci, factorial).
  - **Backtracking:** Ideal for combinatorial problems and those requiring exploration of multiple paths (e.g., puzzles, optimization problems).

- **Process:**
  - **Recursion:** Calls itself with simpler arguments until reaching a base case.
  - **Backtracking:** Tries out each possible move recursively and backtracks upon hitting a dead end to try the next possibility.

### Conclusion

While recursion is a broad technique that can be used in many different problem domains, backtracking is a more specialized technique that leverages recursion to explore potential solutions and backtrack when necessary to find valid solutions. Both are powerful tools in algorithm design and are often used together to solve complex problems efficiently.

---
