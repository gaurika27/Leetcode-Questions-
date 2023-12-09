/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int ans=0;
    int n=nums.size();   
    for(int i=0; i<n; i++){
        ans=ans^nums[i];
        }
        return ans;
        }
}; 
*/
//M2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i) nums[0] ^= nums[i];
        return nums[0];
    }
};