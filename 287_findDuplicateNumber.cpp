class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> count;
        int m=nums.size();
        for(int i=0; i<m; i++){
            count[nums[i]]++;
            }       
        int a=2;
        for (auto it:count) {
            if (it.second>1){
                return it.first;
            }
            
            }
            return -1;
    }


};