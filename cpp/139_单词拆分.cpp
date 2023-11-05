/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-02
 * 46/46 (24 ms)
 * Your runtime beats 20.04 % of cpp submissions
 * Your memory usage beats 9.36 % of cpp submissions (14.7 MB)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (se.count(s.substr(i, j - i))) {
                    // cout << i  << " " << j << endl;
                    dp[j] = dp[j] | dp[i];
                    
                }
            }
        }
        // for_each(dp.begin(), dp.end() , [](const bool a){cout << a << ",";});
        return dp[n];
    }
};
// @lc code=end

/*
"aaaaaaa"\n["aaaa", "aaa"]
*/