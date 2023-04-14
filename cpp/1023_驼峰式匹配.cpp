/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-14
 * 36/36 (4 ms)
 * Your runtime beats 45.38 % of cpp submissions
 * Your memory usage beats 10 % of cpp submissions (7.2 MB)
*/
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int pattern_size = pattern.size();
        pattern_ = pattern;
        vector<bool> res;
        for (auto& query : queries) {
            res.emplace_back(dp(query, 0, 0));
        }
        return res;
    }

private:
    string pattern_;
    unordered_map<string, bool> memo_;
    bool dp(string& query, int i, int j) {
        if (memo_.count(query)) {
            return memo_[query];
        }

        int m = query.size(), n = pattern_.size();
        if (j == n) {
            // 模式已经匹配完成，接下来看queris[i]后面还有没有大写的
            for (; i < m; ++i) {
                if (isupper(query[i])) {
                    memo_[query] = false;
                    return false;
                }
            }
            memo_[query] = true;
            return true;
        }

        if (i == m) {
            memo_[query] = false;
            return false;
        }

        // 有两种情况
        // 1. query[i] == pattern_[j] 有 dp(i + 1, j + 1)
        // 2. query[i] != pattern_[j]
        //  a. query[i]是大写字母则false
        //  b. 否则 dp(i + 1, j)
        int res = false;
        if (query[i] == pattern_[j]) {
            res = dp(query, i + 1, j + 1);
        } else if (!isupper(query[i])) {
            res = dp(query, i + 1, j);
        }
        memo_[query] = res;
        return res;
    }
};
// @lc code=end
/*
["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]\n
"FB"\n
["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]\n
"FoBa"\n
["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]\n
"FoBaT"\n
["foobar","FooBarTest","football","FrameBuffer","forcebeedBack","forcebeedback"]\n
"fb"\n
["CompetitiveProgramming","CounterPick","ControlPanel"]\n
"CooP"\n
*/