//optimised solution
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mark;
        for (int val : arr){
            mark[val] = 0;
        }
        for (int val : arr){
            mark[val]++;
        }

        unordered_set<int> vas;
        for (auto it : mark){
            vas.insert(it.second);
        }
        return vas.size() == mark.size();
    }
};