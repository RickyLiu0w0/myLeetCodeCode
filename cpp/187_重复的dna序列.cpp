/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted
 * 31/31 cases passed (44 ms)
 * Your runtime beats 84.21 % of cpp submissions
 * Your memory usage beats 21.22 % of cpp submissions (23.2 MB)
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int n = s.length();
        vector<string> res;
        for (int i = 0; i + 10 <= n; ++i) {
            string sub = s.substr(i, 10);
            if (mp.count(sub) && mp[sub] == 1) {
                // cout << "add " << sub << endl;
                res.emplace_back(sub);
            }
            mp[sub]++;
            // cout << sub << ": " << mp[sub] << endl;
        }
        return res;
    }
};
// @lc code=end

/*
"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"\n
"AAAAAAAAAAAAA"\n
"AAAAAAAAAAA"
*/