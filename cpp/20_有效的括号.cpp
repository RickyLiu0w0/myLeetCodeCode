/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-03
 * 93/93 (4 ms)
 * Your runtime beats 37.15 % of cpp submissions
 * Your memory usage beats 57.03 % of cpp submissions (6.2 MB)
*/
class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1) {
            return false;
        }
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (!st.empty() && get_left(c) != st.top()) {
                    return false;
                }
                if (st.empty()) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

private:
    char get_left(char c) {
        switch (c) {
            case ')':
                return '(';
            case ']':
                return '[';
            default:
                return '{';
        }
    }
};
// @lc code=end
/*
"({[)"
*/