/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

//Optimal Solution:

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        vector<int> copyBuffer(n);
        return mergesort(nums.begin(), nums.end(), copyBuffer.begin(), copyBuffer.end());
    }

private:
    template <typename It>
    int mergesort(It begin, It end, It copyBegin, It copyEnd) {
        if (begin + 1 >= end) { return 0; }

        int splitIdx = (end - begin) / 2;
        It split = begin + splitIdx;
        It copySplit = copyBegin + splitIdx;

        int result = 0;
        result += mergesort(begin, split, copyBegin, copySplit);
        result += mergesort(split, end, copySplit, copyEnd);

        result += countReversePairs(begin, split, end);
        merge(begin, split, end, copyBegin, copyEnd);

        return result;
    }

    template <typename It>
    void merge(It begin, It split, It end, It copyBegin, It copyEnd) {
        It place = copyBegin;
        It source1 = begin;
        It source2 = split;
        while (source1 != split && source2 != end) {
            if (*source1 <= *source2) {
                *place = *source1;
                ++source1;
            } else {
                *place = *source2;
                ++source2;
            }
            ++place;
        }

        while (source1 != split) {
            *place = *source1;
            ++place;
            ++source1;
        }

        while (source2 != end) {
            *place = *source2;
            ++place;
            ++source2;
        }

        assert(place == copyEnd);
        for (It from = copyBegin, to = begin; to != end; ++from, ++to) {
            *to = *from;
        }
    }

    template <typename It>
    int countReversePairs(It begin, It split, It end) {
        int count = 0;

        It it2 = split;
        for (It it1 = begin; it1 != split; ++it1) {
            int lowIndexVal = *it1;
            int highIndexUpperBound = *it1 / 2;
            if (lowIndexVal > 0 && lowIndexVal % 2 == 1) { ++highIndexUpperBound; }
            while (it2 != end && *it2 < highIndexUpperBound) {
                ++it2;
            }
            count += (it2 - split);
        }

        return count;
    }
};


//My solution:

class Solution {
private: 
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }
public:
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
};