/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-02-21
 * 37/37  (4 ms)
 * Your runtime beats 99.37 % of cpp submissions
 * Your memory usage beats 60.13 % of cpp submissions (14.3 MB)
*/
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int right_most = 0;                 // 最远记录
        int breakpoint = 0;                 // 当前覆盖到哪里
        int res = 0;
        vector<int> right_range(n + 1, 0);  // 存储第i点到最远的距离

        for (int i = 0; i <= n; ++i) {
            int left = std::max(0, i - ranges.at(i));
            int right = std::min(n, i + ranges.at(i));
            right_range.at(left) = std::max(right_range.at(left), right);
        }

        for (int i = 0; i < n; ++i) {
            right_most = std::max(right_most, right_range.at(i));  // 获取第i点最远到哪里

            if (i == breakpoint) {
                // 当前覆盖到breakpoint，遍历到i（左端点），相等时开始开新的水龙头
                if (right_most <= i) {
                    // 当前最远都覆盖不了当前位置，或仅仅覆盖，右边无法覆盖
                    return -1;
                } else {
                    ++res;
                    breakpoint = right_most;
                }
            }
        }

        return res;
    }
};
// @lc code=end
