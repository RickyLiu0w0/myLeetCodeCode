/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-13
 * 8/8 (20 ms)
 * Your runtime beats 5.62 % of cpp submissions
 * Your memory usage beats 5.66 % of cpp submissions (20.1 MB)
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        backTreack(n, n, str);
        return res;
    }
private:
    void backTreack(int left, int right, string& path) {
        if (left < 0 || right < 0) {
            return;
        }

        if (left > right) {
            // 左边括号比右边小，不合法
            return;
        }

        if (left == 0 && left == right) {
            // 一个合法情况
            res.emplace_back(path);
            return;
        }

        path.push_back('(');
        backTreack(left - 1, right, path);
        path.pop_back(); // 撤销选择

        path.push_back(')');
        backTreack(left, right - 1, path);
        path.pop_back(); // 撤销选择

        return;
    }
    vector<string> res;
};
// @lc code=end

