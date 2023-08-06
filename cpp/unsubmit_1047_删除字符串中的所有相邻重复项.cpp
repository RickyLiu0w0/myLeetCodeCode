/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> d;
        for (char c : s) {
            if (!d.empty() && d.back() == c) {
                d.pop_back();
            } else {
                d.push_back(c);
            }
        }
        string res = "";
        for (char c : d) {
            res.push_back(c);
        }

        return res;
    }
};
// @lc code=end

