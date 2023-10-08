/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-18
 * 128/128 (16 ms)
 * Your runtime beats 43.92 % of cpp submissions
 * Your memory usage beats 5.02 % of cpp submissions (9 MB)
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> ma;
        for (char c : magazine) {
            ma[c]++;
        }
        for (char c : ransomNote) {
            if (ma.count(c) && ma[c]) {
                ma[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

