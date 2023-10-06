/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-21
 * 42/42 (12 ms)
 * Your runtime beats 28.89 % of cpp submissions
 * Your memory usage beats 5.12 % of cpp submissions (7.6 MB)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> ma;
        for (auto c : s) {
            ma[c]++;
        }
        for (auto c : t) {
            if (!ma.count(c)) {
                return false;
            }
            ma[c]--;
            if (!ma[c]) {
                ma.erase(c);
            }
        }
        return true;
    }
};
// @lc code=end

