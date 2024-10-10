https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack

#### Next Greater Element I
(https://leetcode.com/problems/next-greater-element-i/description/)

```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;

        unordered_map<int, int> nge;

        vector<int> ans;

        for(int i=nums2.size()-1; i>=0; i--){

            while(!st.empty() && st.top()<=nums2[i]){

                st.pop();

            }

  

            if(st.empty()) nge.insert({nums2[i], -1});

            else nge.insert({nums2[i], st.top()});

  

            st.push(nums2[i]);

        }

  

        for(int i=0; i<nums1.size(); i++){

            ans.push_back(nge[nums1[i]]);

        }

  

        return ans;

    }
```


#### Next Greater Element II
(https://leetcode.com/problems/next-greater-element-ii/)

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {

        int max=-1e7, maxInd = -1;

        for(int i=0; i<nums.size(); i++){

            if(nums[i]>max){

                max = nums[i];

                maxInd = i;

            }

        }

        vector<int> ans = nums;

        stack<int> nge;


        for(int i=maxInd; i>=0; i--){

            while(!nge.empty() && nge.top() <= ans[i]) nge.pop();

            int x = ans[i];

            if(nge.empty()) ans[i] = -1;

            else ans[i] = nge.top();

            nge.push(x);

        }

  

        for(int i=ans.size()-1; i>=maxInd+1; i--){

            while(!nge.empty() && nge.top() <= ans[i]) nge.pop();  

            int x = ans[i];

            if(nge.empty()) ans[i] = -1;

            else ans[i] = nge.top();

            nge.push(x);

        }

        return ans;
    }
```

Calculate the max element, and as the next greater element for the max element will be -1, used that as the end point from where to start the process of calculating nge for the remaining elements. After that I traversed from that index to 0 in 1 loop, and then from the end to that index in another loop to calculate NGEs for all the elements.


