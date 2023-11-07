/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-07
 * 290/290 (4 ms)
 * Your runtime beats 58.93 % of cpp submissions
 * Your memory usage beats 21.27 % of cpp submissions (7 MB)
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> char_cnt;
        unordered_map<char, int> char_cnt2;
        for (char c : s) {
            char_cnt[c]++;
        }
        string res;
        for (char c : s) {
            if (char_cnt2.count(c) && char_cnt2[c]) {
                char_cnt[c]--;
                continue;
            }
            while (res.length() && c <= res.back() && char_cnt[res.back()] > 1) {
                char_cnt[res.back()]--;
                char_cnt2[res.back()]--;
                res.pop_back();
            }
            res.push_back(c);
            char_cnt2[c]++;
        }

        return res;
    }
};
// @lc code=end

/*
"bcabc"\n
"cbacdcbc"\n
"abccddc"\n
"abbbcbbba"\n
"cdadabcc"\n
"abacb"\n
"bbcaac"\n
*/
