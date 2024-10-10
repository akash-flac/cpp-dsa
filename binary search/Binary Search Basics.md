
## Iterative Implementation
```cpp
int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = (s+e)/2;

        while(s<=e){
            if(target == nums[mid])
                return mid;

            if(target > nums[mid])
                s = mid+1;

            else if(target < nums[mid])
                e = mid-1;

            mid = (s+e) / 2;
        }

        return -1;
    }
```

## Recursive Implementation
```cpp
int binarySearch(vector<int>& nums, int target, int low, int high){

        if(low>high) return -1;
        int mid = low+high/2;  

        if(nums[mid] == target) return mid;
        else if(nums[mid]<target){
            return binarySearch(nums, target, mid+1, high);
        }
        return binarySearch(nums, target, low, mid-1);
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);        
    }
```

## Lower Bound : smallest index such that `arr[ind] >= x`
(https://www.naukri.com/code360/problems/lower-bound_8165382?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries)

```cpp
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low + high) / 2;
            //maybe an answer
            if(arr[mid] >= x){
                ans = mid;
                //look for more smaller indices on the left
                high = mid-1;
            }
            else{
                low = mid+1;//look for right
            }
        }
        return ans;
}
```

In C++ STL, a procedure called lower_bound can be used.
Eg. 
```cpp
lb = lower_bound(arr.begin(), arr.end(), n)
```
To get the index of the lower_bound, we just need to do the following:
```cpp
lb = lower_bound(arr.begin(), arr.end(), n) - arr.begin();
```

T.C. - O(logn)

## Upper Bound : smallest index such that `arr[ind] > x`
(https://www.naukri.com/code360/problems/implement-upper-bound_8165383?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries)

```cpp
int upperBound(vector<int> &arr, int x, int n){
    int low = 0, high = n-1;
    int ans = n;
        while(low<=high){
            int mid = (low + high) / 2;
           
            //maybe an answer
            if(arr[mid] > x){
                ans = mid;
                //look for more smaller indices on the left
                high = mid-1;
            }
            else{
                low = mid+1;//look for right
            }
        }
        return ans; 
}
```

## Search Insert Position
(https://leetcode.com/problems/search-insert-position/description/)

```cpp
int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
```


