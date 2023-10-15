/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-07
 * 231/231 (8 ms)
 * Your runtime beats 31.04 % of cpp submissions
 * Your memory usage beats 5.01 % of cpp submissions (8.1 MB)
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (-1 != st.top()) {
                    int index = st.top();
                    if (s[index] == '(') {
                        // 匹配成功
                        st.pop();
                        res = max(res, i - st.top());
                    } else {
                        st.push(i);
                    }
                } else {
                    st.push(i);
                }
            }
        }
        return res;
    }

    int longestValidParentheses1(string s) {
        int n = s.length();
        int res = 0;
        vector<int> dp(n + 1, 0);
        stack<int> st; // 存储左括号的下标
        // dp[i]为到第i为止的合法字符串的长度
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
                dp[i + 1] = 0; // 以(结尾的一定不是合法字符串，重置为0
            } else {
                if (!st.empty()) {
                    int left = st.top();
                    st.pop();
                    int len = 1 + i - left + dp[left];
                    res = max(res, len);
                    dp[i + 1] = len;
                } else {
                    dp[i + 1] = 0; // 以)结尾的而且没找到(，一定不是合法字符串，重置为0
                }
            }
        }
        return res;
    }
};
// @lc code=end

