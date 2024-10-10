#### Sliding Window + Binary Search
(https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14)
(https://youtu.be/hx8Ssz_3XSs?si=-cEFHRCTZ55_ocAR)

```cpp
class Solution {

    //sliding window + binary search

    private:

    int slidingWindowCount(vector<int>nums, int D){

        int i=0;

        int j=1;

        int n=nums.size();

        int pairCount=0;

  

        while(j<n){

            while(nums[j]-nums[i]>D){

                i++;

            }

  

            pairCount += (j-i);

            j++;

        }

  

        return pairCount;

    }

public:

    int smallestDistancePair(vector<int>& nums, int k) {

        int n = nums.size();

       sort(begin(nums), end(nums));

  

       int low=0, high=nums[n-1]-nums[0];

  

       int result=0;

  

       while(low<=high){

        int mid = low + (high-low)/2;

  

        int countPair = slidingWindowCount(nums, mid);

  

        if(countPair < k){

            low = mid+1;

        }

        else{

            result = mid;

            high = mid-1;

        }

       }

        return result;

    }

};
```

