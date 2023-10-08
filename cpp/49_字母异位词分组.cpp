/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-21
 * 120/120 (32 ms)
 * Your runtime beats 64.59 % of cpp submissions
 * Your memory usage beats 92.79 % of cpp submissions (18.2 MB)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int n = 0, len = strs.size(); // 记录当前下标
        unordered_map<string, int> ma; // 一种模式和他的下标
        for (int i = 0; i < len; ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());

            if (!ma.count(s)) {
                ma[s] = n++;
                res.emplace_back(vector<string>{});
            }
            res[ma[s]].emplace_back(strs[i]);
        }
        return res;
    }
    
};
// @lc code=end

/*
["eat","tea","tan","ate","nat","bat"]\n
[""]\n
["a"]
*/