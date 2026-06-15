Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


#### M1
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        
        int mx=INT_MIN;
        for(auto it: nums){
            hash[it]++;
        } 
        int maxFreq = 0;
        int element = -1;
        for (auto& [key, value] : hash) {
            if (value > maxFreq) {
                maxFreq = value;
                element = key;
            }
        }
        return element;        
    }
};
```

#### M2
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        map<int, int> mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        for(auto it:mpp){
            if(it.second>n/2){
                res.push_back(it.first);
            }
        }
        int maxElement = *std::max_element(res.begin(), res.end());
        return maxElement;

        
    }
};
```

#### M3
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // optimal solution

         int ele = nums[0];
         int count = 0;
         int n = nums.size();
        
         for(int i = 0;i<n;i++)
         {

            if(count == 0)
            {
                ele = nums[i];
                count ++;
            }
     
            else if(nums[i] == ele) count ++;
            else count --;
          
         }
        
        return ele;
    }
};
```
