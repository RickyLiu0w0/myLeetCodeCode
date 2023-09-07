/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-28
 * 156/156 (24 ms)
 * Your runtime beats 20.28 % of cpp submissions
 * Your memory usage beats 68.9 % of cpp submissions (16.6 MB)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end());

        int begin = intervals.front()[0], end = intervals.front()[1], i = 1, n = intervals.size();
        vector<vector<int>> res;
        while (i < n) {
            if (intervals[i][0] > end) {
                res.emplace_back(vector<int>{begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
            i++;
        }
        res.emplace_back(vector<int>{begin, end});
        return res;
    }
};
// @lc code=end

/*
[[1,3],[6,9]]\n[2,5]\n
[[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
[]\n[5,7]\n
[[1,5]]\n[2,3]\n
[[1,5]]\n[2,7]
*/