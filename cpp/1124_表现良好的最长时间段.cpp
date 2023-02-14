/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

#include "AllInclude.h"

/**
 * Accepted 2023-02-14
 * 98/98 cases passed (24 ms)
 * Your runtime beats 67.33 % of cpp submissions
 * Your memory usage beats 95.33 % of cpp submissions (21.3 MB)
 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0;
        size_t size = hours.size();
        int pre_sum[size + 1];  // 前缀和数组
        stack<int> st;
        st.push(pre_sum[0] = 0);

        for (size_t j = 1; j <= size; ++j) {
            pre_sum[j] = pre_sum[j - 1] + (hours.at(j - 1) > 8 ? 1 : -1);

            if (pre_sum[st.top()] > pre_sum[j]) {
                st.push(j);
            }
        }

        for (int i = size; i; i--) {
            while(!st.empty() && pre_sum[i] > pre_sum[st.top()]) {
                res = res < i - st.top() ? i - st.top() : res;
                st.pop();
            }
        }

        return res;
    }
};
// @lc code=end
