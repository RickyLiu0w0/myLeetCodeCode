/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-30
 * 54/54 cases passed (324 ms)
 * Your runtime beats 14.58 % of cpp submissions
 * Your memory usage beats 75 % of cpp submissions (64.6 MB)
 */
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin() ,points.end(), [](vector<int>& a, vector<int>&b){
            return a[0] < b[0];
        });

        int res = 0;
        int size = points.size();

        for (int i = 1; i < size; ++i) {
            res = max(res, points[i][0] - points[i - 1][0]);
        }
        return res;
    }
};
// @lc code=end

