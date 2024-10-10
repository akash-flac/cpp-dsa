(https://www.geeksforgeeks.org/sorting-algorithms/)
*Sorting* refers to rearrangement of a given array or list of elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of elements in the respective data structure. Sorting means reordering of all the elements either in ascending or in descending order.

## Selection Sort
```cpp
//Selection Sort
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++){
        // Find the minimum element in
        // unsorted array
        int mini = i;
        for (int j = i + 1; j < nums.size(); j++){
            if (nums[j] < nums[mini])
                mini = j;
        }
        // Swap the found minimum element
        // with the first element
        if (mini != i)
            swap(nums[mini], nums[i]);

        }
        return nums;
    }
```

## Insertion Sort
```cpp
//Insertion Sort
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int key = nums[i];
            int j = i - 1;  

            /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */

            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
        nums[j + 1] = key;
    }
    return nums;
    }
```

## Bubble Sort
```cpp
//Bubble Sort
    vector<int> sortArray(vector<int>& arr) { 
        for (int i = arr.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    return arr;
    }
```




