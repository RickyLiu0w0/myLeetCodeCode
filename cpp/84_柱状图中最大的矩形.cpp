/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-02
 * 98/98 (128 ms)
 * Your runtime beats 77.32 % of cpp submissions
 * Your memory usage beats 58.65 % of cpp submissions (75.7 MB)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0);
        heights.insert(heights.begin() ,0);
        int n = heights.size(), res = 0;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur = heights[st.top()];
                st.pop();
                res = max(res, (i - st.top() - 1) * cur);
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

