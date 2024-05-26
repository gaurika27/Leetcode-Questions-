/*
An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

Example 1:

Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
Example 2:

Input: n = 1
Output: 3
Example 3:

Input: n = 10101
Output: 183236316
 

Constraints:

1 <= n <= 105
*/
class Solution {
public:
    static const int MOD = 1000000007;

    int check_all_records(int cur_ind, int count_a, int count_l, int n, vector<vector<vector<int>>>& temp) {
        if (cur_ind == n) {
            return 1;
        }
        if (temp[cur_ind][count_a][count_l] != -1) {
            return temp[cur_ind][count_a][count_l];
        }
        int with_a_next = (count_a == 0) ? check_all_records(cur_ind + 1, count_a + 1, 0, n, temp) : 0;
        int with_l_next = (count_l == 2) ? 0 : check_all_records(cur_ind + 1, count_a, count_l + 1, n, temp);
        int with_p_next = check_all_records(cur_ind + 1, count_a, 0, n, temp);
        int total = ((with_a_next + with_l_next) % MOD + with_p_next) % MOD;

        temp[cur_ind][count_a][count_l] = total;
        return total;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> temp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return check_all_records(0, 0, 0, n, temp);
    }
};