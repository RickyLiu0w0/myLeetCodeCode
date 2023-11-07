/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-07
 * 1053/1053 ;passed (24 ms)
 * Your runtime beats 16.57 % of cpp submissions
 * Your memory usage beats 12.95 % of cpp submissions (31.7 MB)
*/
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        int res = 0;
        while (left <= right) {
            string s = words[left++];
            res += (vowel.count(s.front()) && vowel.count(s.back()));
        }
        return res;
    }
};
// @lc code=end

