/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-10
 * 34/34 (20 ms)
 * Your runtime beats 83 % of cpp submissions
 * Your memory usage beats 48.02 % of cpp submissions (11.1 MB)
 */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)->bool {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int res = intervals.size();
        int n = res, left = intervals[0][0], right = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < right && intervals[i][1] <= right) {
                --res;
            } else if (intervals[i][0] > right) {
                left = intervals[i][0];
                right = intervals[i][1];
            } else {
                right = intervals[i][1];
            }
        }

        return res;
    }
};
// @lc code=end

