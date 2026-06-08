You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

 

Example 1:

Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
Example 2:

Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105

```
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftsum=0, rightsum=0;
        vector<int> ans(nums.size());
        
        for(int i=0; i<nums.size(); i++){
            ans[i]=leftsum;
            leftsum+=nums[i];          
        }  
        for(int i=nums.size()-1; i>=0; --i){
            ans[i]=abs(ans[i]-rightsum);
            rightsum+=nums[i];
        }      
        return ans;
    }
};
```

```
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        const int n=nums.size();
        int lsum=0, rsum=accumulate(nums.begin(), nums.end(), 0);
        for(int i=0; i<n; i++){
            const int x=nums[i];
            rsum-=x;
            nums[i]=(rsum>=lsum)?rsum-lsum:lsum-rsum;
            lsum+=x;
        }
        return nums;
    }
};
```
