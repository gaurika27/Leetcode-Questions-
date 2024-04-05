/*
 Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/
//M1:Brute
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){   
                sum+=nums[j];
                if(sum==k) count++;
            }
            
        }
        return count;
        
    }
};
//M2:Better
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){   
                sum+=nums[j];
                if(sum==k) count++;
            }
            
        }
        return count;
        
    }
};
//M3:Optimal
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0, preSum=0, n=nums.size();
        map<int, int> mpp;
        mpp[0]=1;
        for(int i:nums){
            preSum+=i;
            int remove=preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]+=1;  
        }
        return cnt; 
    }
};