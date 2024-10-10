# Arrays
1. Set Matrix Zeroes: 
	1. Use 2 sets for row and col, and store the index of the row or col if there is a zero. Then traverse the whole matrix, and check for index if the i is part of the row set or j is part of the col set for each `matrix[i][j]`, and accordingly make that index 0. 
	2. To do it in-place:
2. Pascal's Triangle: `temp[j] = res[i-1][j] + res[i-1][j-1];`
3. Next Permutation: 
4. Maximum Subarray Sum: Kadane's Algorithm->sum up each index while traversing the array, and do `maxi = max(sum, maxi)`, and if sum<0, then do sum=0, because adding a negative sum to the original answer is only gonna decrease the max sum possible.
5. Sort 0s, 1s, and 2s: Dutch National Flag algo-> 3 pointers i.e. low, mid, high, and mid will move from low(index 0) to high(index n-1), and if 0 is found, `swap(nums[mid], nums[low])`, else if 2 is found, `swap(nums[mid], nums[high])`, else if 1 is found, just increment the mid pointer.
6. Buy and Sell Stock: 
7. Rotate Matrix: 
8. Merge Overlapping Subintervals: 
9. Merge Two Sorted Arrays w/o extra space:
10. find duplicate in array of n+1 integers
11. repeat and missing number: 
12. inversion of array: 