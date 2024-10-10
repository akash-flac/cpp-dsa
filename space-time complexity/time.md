![](attachments/Complexity%20Chart.png)

![](attachments/Data%20Structures.png)

![](attachments/Data%20Structures%20Selection.png)

### Time Complexity Analysis of Binary Search

### Analysis of Worst Case Complexity

In the worst case of the algorithm we would be finding the element in the last iteration of the Binary Search Algorithm and at each step of the iteration, the size of the array reduces to half so there can be at max of total of log2Nlog2​N iterations hence the Worst Case Complexity of the algorithm is O(log2N)O(log2​N).

In case the above reasoning wasn't clear to you, think of it this way:

Let 2k2k be the first power of 22 which is ≥N≥N. Now, if we do a binary search on an array of size 2k2k, after the first step, the 'solution space' would be 2k2=2k−122k​=2k−1. Similarly, after the second step, it would be 2k−12=2k−222k−1​=2k−2, and so on. So clearly, within kk steps, we reach a size of 20=120=1, which is our termination case. So we spend O(k)O(k) time. And kk is nothing but ceil(log2N)ceil(log2​N), which is at most log2N+1log2​N+1, which is O(log2N)O(log2​N).

We can show that the average case complexity is also O(log2N)O(log2​N).