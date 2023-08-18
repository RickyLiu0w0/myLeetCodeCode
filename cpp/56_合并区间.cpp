/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-12
 * 170/170 (28 ms)
 * Your runtime beats 93.98 % of cpp submissions
 * Your memory usage beats 61.9 % of cpp submissions (18.5 MB)
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0], r = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> res;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] > r) {
                // 新的一个区间
                res.emplace_back(vector<int>{l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            } else {
                r = max(r, intervals[i][1]);
            }
        }
        res.emplace_back(vector<int>{l, r});
        return res;
    }
};
// @lc code=end

