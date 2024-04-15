/*
You are given an array of positive integers nums.

Return the number of 
subarrays
 of nums, where the first and the last elements of the subarray are equal to the largest element in the subarray.

 

Example 1:

Input: nums = [1,4,3,3,2]

Output: 6

Explanation:

There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:

subarray [1,4,3,3,2], with its largest element 1. The first element is 1 and the last element is also 1.
subarray [1,4,3,3,2], with its largest element 4. The first element is 4 and the last element is also 4.
subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [1,4,3,3,2], with its largest element 2. The first element is 2 and the last element is also 2.
subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.
Hence, we return 6.

Example 2:

Input: nums = [3,3,3]

Output: 6

Explanation:

There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:

subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
Hence, we return 6.

Example 3:

Input: nums = [1]

Output: 1

Explanation:

There is a single subarray of nums which is [1], with its largest element 1. The first element is 1 and the last element is also 1.

Hence, we return 1.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/
class Solution {
public:
    
    int find(vector<int> &nums, int l, int r)
    {
        int ans=nums[l];
        
        for(int i=l;i<=r;i++)
        {
            ans=max(ans,nums[i]);
        }
        
        return ans;
    }
    
    long long numberOfSubarrays(vector<int>& nums) {
        
        unordered_map<int,vector<int>> v;
        
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]].push_back(i);
        }
        
        long long ans=nums.size();
        
        for(auto x:v)
        {
            long long cnt=1;
            
            for(int i=1;i<x.second.size();i++)
            {
                if(find(nums,x.second[i-1],x.second[i])==x.first)
                {
                    cnt+=1;
                }
                else
                {
                    ans+=cnt*(cnt-1)/2;
                    cnt=1;
                }
            }
            
            ans+=cnt*(cnt-1)/2;
        }
        
        return ans;
    }
};