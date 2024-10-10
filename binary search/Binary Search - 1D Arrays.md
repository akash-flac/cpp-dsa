#### Floor
(https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array)

```cpp
int findFloor(vector<long long> v, long long n, long long x) {
        int low = 0, high = n-1;
        int ans = -1;
        
        while(low<=high){
            int mid = (low + high) / 2;
            //maybe an answer
            if(v[mid] <= x){
                ans = mid;
                //look for more smaller indices on the left
                low = mid+1;
            }
            
            else{
                high = mid-1;//look for right
            }
        }
        return ans;
        
    }
```

==Note==: Focus on if the range of low and high, and the fact that when we calculate 'mid', is it greater than or less than the desired answer we're looking for and accordingly, eliminate one part of the array, and update 'low' or 'high'.

#### Floor and Ceil
(https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401)

```cpp
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int low = 0, high = n-1;
        int floor = -1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(a[mid] <= x){
                floor = a[mid];
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        low = 0, high = n-1;
        int ceil = -1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(a[mid] >= x){
                ceil = a[mid];
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {floor, ceil};
}
```

==Note== : Here, the question asked for the floor and ceil of the given 'x', and not the indices of the floor and ceil, so gotta be careful with that. Other than that, it's important to make sure to initialize the 'floor' and 'ceil' variables with either -1, n(size of array), INT_MAX, INT_MIN, etc. so that one of these get returned when we don't find the requisite answer within the array.

#### First and Last Occurrence of an Element In a Sorted Array
```cpp
vector<int> searchRange(vector<int>& nums, int target) {

        int low=0, high=nums.size()-1;

        int first=-1, last=-1;

        while(low<=high){

            int mid = (low+high)/2;

            if(nums[mid]==target){

                first = mid;

                high = mid-1;

            }

            else if(nums[mid]<target){

                low = mid+1;

            }

            else if(nums[mid]>target){

                high = mid-1;

            }

        }


        low=0, high=nums.size()-1;

        while(low<=high){

            int mid = (low+high)/2;

            if(nums[mid]==target){

                last = mid;

                low = mid+1;

            }

            else if(nums[mid]<target){

                low = mid+1;

            }

            else if(nums[mid]>target){

                high=mid-1;

            }

        }

        vector<int> result(2);

        result[0] = first;

        result[1] = last;

        return result;

    }

```

==Note== : Here, to find the first and last occurrences, I run 2 separate loops to find each of them.
To find the first occurrence, the trick is to eliminate the right half of the range as soon as you find one occurrence of the target. And we try to keep finding the leftmost occurrence. Similarly, we find the last occurrence of the target as well.

#### Count occurrences of an element in an array
(https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence)

==Note== : Sort the array, then find the first and last occurrences of the given element. 
Do `last-first+1`  to get the answer. If there is no occurrence of the given element, then both 'first' and 'last' will not update and the value will remain -1, and hence we can return 0 for that case.

#### Search in Rotated Sorted Array 
(https://leetcode.com/problems/search-in-rotated-sorted-array/)

```cpp
int search(vector<int>& nums, int target) {

        int n=nums.size();

        int low = 0, high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

  

        //if mid points the target

        if (nums[mid] == target) return mid;

  

        //if left part is sorted:

        if (nums[low] <= nums[mid]) {

            if (nums[low] <= target && target <= nums[mid]) {

                //element exists:

                high = mid - 1;

            }

            else {

                //element does not exist:

                low = mid + 1;

            }

        }

        else { //if right part is sorted:

            if (nums[mid] <= target && target <= nums[high]) {

                //element exists:

                low = mid + 1;

            }

            else {

                //element does not exist:

                high = mid - 1;

            }

        }

    }

    return -1;

    }
```

#### Search in Rotated Sorted Array II 
(https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

```cpp
bool search(vector<int>& nums, int target) {

        int n = nums.size(); // size of the array.

    int low = 0, high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        //if mid points the target

        if (nums[mid] == target) return true;
        //Edge case:

        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {

            low = low + 1;

            high = high - 1;

            continue;

        }
        //if left part is sorted:

        if (nums[low] <= nums[mid]) {

            if (nums[low] <= target && target <= nums[mid]) {

                //element exists:

                high = mid - 1;

            }

            else {

                //element does not exist:

                low = mid + 1;

            }

        }

        else { //if right part is sorted:

            if (nums[mid] <= target && target <= nums[high]) {

                //element exists:

                low = mid + 1;

            }

            else {

                //element does not exist:

                high = mid - 1;

            }

        }

    }

    return false;
    }
```


#### Find Minimum in Rotated Sorted Array
(https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

```cpp
int findMin(vector<int>& nums) {

        int low = 0, high = nums.size() - 1;

        int ans = INT_MAX;

        while (low <= high) {

        int mid = (low + high) / 2;

  

        //if left part is sorted:
        if (nums[low] <= nums[mid]) {

            // keep the minimum:
            ans = min(ans, nums[low]);

            // Eliminate left half:
            low = mid + 1;

        }

        else { //if right part is sorted:
            // keep the minimum:
            ans = min(ans, nums[mid]);

            // Eliminate right half:
            high = mid - 1;
            }
        }
    return ans;
    }
```

OR

```cpp
int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (nums[low] <= nums[high]) {
            ans = min(ans, nums[low]);
            break;
        }
        //if left part is sorted:
        if (nums[low] <= nums[mid]) {
            // keep the minimum:
            ans = min(ans, nums[low]);

            // Eliminate left half:
            low = mid + 1;
        }

        else { //if right part is sorted:
            // keep the minimum:
            ans = min(ans, nums[mid]);
            
            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
    }
```

#### Single Element in a Sorted Array 
(https://leetcode.com/problems/single-element-in-a-sorted-array/) 

```cpp

```

![](attachments/Pasted%20image%2020240816140652.png)

![](attachments/Pasted%20image%2020240816140739.png)


