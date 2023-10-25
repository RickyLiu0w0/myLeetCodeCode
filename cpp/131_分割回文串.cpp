/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-25
 * 32/32 (100 ms)
 * Your runtime beats 90.88 % of cpp submissions
 * Your memory usage beats 94.89 % of cpp submissions (48.4 MB)
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        // 回溯
        int n = s.length();
        vector<vector<string>> res;
        vector<string> path;
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                // 遍历完全部
                res.emplace_back(path);
                return;
            }

            for (int j = i; j < n; ++j) {
                string tmp = s.substr(i, j - i + 1);
                string tmp2 = tmp;
                reverse(tmp.begin(), tmp.end());
                if (tmp == tmp2) {
                    path.emplace_back(move(tmp2)); // 选择
                    dfs(j + 1);
                    path.pop_back(); // 撤销选择
                }
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end

