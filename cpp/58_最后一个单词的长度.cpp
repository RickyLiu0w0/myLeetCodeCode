/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-10
 * 58/58 (4 ms)
 * Your runtime beats 45.12 % of cpp submissions
 * Your memory usage beats 55.26 % of cpp submissions (6.4 MB)
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        int res = 0;
        while (getline(ss, s, ' ')) {
            if (s.length()) {
                res = s.length();
            }
        }    
        return res;
    }
};
// @lc code=end

/*
"Hello World"\n
"   fly me   to   the moon  "\n
"luffy is still joyboy"\n
"  d  "\n
*/