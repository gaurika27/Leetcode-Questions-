/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

//Method 1:Brute Force Method
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> st;
        for(int i: nums){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    for(int l=k+1; l<n; l++){
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target){
                            vector<int> temp={nums[i]+nums[j]+nums[k]+nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }

        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//Method 2:Better Solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> st;
        for(int i:nums){
            for(int j=i+1;j<n; j++){
                set<long long> hashset;
                for(int k=j+1; k<n; k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth=target-(sum);
                    if(hashset.find(fourth)!=hashset.end()){
                        vector<int> temp={nums[i]+nums[j]+nums[k]+nums[fourth]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;

    }
};