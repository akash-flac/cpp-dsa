## Different Patterns
1. Constant Window
2. Longest subarray/substring where `<condition>`
	1. Brute Force - Generate all subarrays ![[Pasted image 20240628153910.png]] ![[Pasted image 20240628153938.png]] 
	2. Better - Initially keep, l=0 & r=0, and then expand or shrink the window according to the condition ![[Pasted image 20240628154148.png]] ![[Pasted image 20240628154204.png]] 
	3. Optimal - only possible in cases like these where the length of the subarray is asked, and not the subarray itself. here, when we expand r when the condition is met, but when the condition is not met, we shrink l only up until the 'maxLength' we already we calculated, and not according to the condition. We do so because we want the 'maxLength' and shrinking smaller than the maxLength won't be of no use, and so we move 'l' only until     `r-l+>= maxLen` 
3. No. of subarrays where `<condition>`
	1. Solved using pattern 2
	2.  It is difficult to determine whether to expand or shrink the window when the condition has no range but is a constant. Hence, we do the following: ![[Pasted image 20240628153206.png]] `k = x-y`
	
4.  Shortest/Minimum Window where `<condition>` 
