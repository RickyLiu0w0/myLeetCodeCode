/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-27
 * 84/84 (88 ms)
 * Your runtime beats 55.39 % of cpp submissions
 * Your memory usage beats 43.86 % of cpp submissions (17 MB)
*/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> memo;
        for (auto& word: words) {
            memo[word] = 0;
        }

        function<int(string)> dp = [&](string s) -> int {
            if (memo[s]) {
                return memo[s];
            }
            int n = s.length(), dp_res = 0;
            for (int i = 0; i < n; ++i) {
                string t = s.substr(0, i) + s.substr(i + 1);
                if (memo.count(t)) {
                    dp_res = max(dp_res, dp(t));
                }
            }
            memo[s] = ++dp_res;
            return dp_res;
        };

        int res = 0;
        for (auto& word: words) {
            res = max(res, dp(word));
        }
        return res;
    }
};
// @lc code=end

