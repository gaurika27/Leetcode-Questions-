//M2: Better:Using STL 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        // 
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }  
        return;    
    }
    
};

//M3: Optimal
class Solution {
public:
    void nextPermutation(vector<int>& nums) {   
    int ind=-1, n=nums.size();
    for(int i=n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            ind=i;
            break;
        }
    }
    
    for(int i=n-1; i>=ind && ind!=-1; i--){
        if(nums[i]>nums[ind]){
            swap(nums[i], nums[ind]);
            break;}
    }
    reverse(nums.begin()+ind+1, nums.end());
   
    }
};
