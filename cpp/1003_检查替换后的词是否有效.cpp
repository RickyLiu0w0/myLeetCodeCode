/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-05-03
 * 95/95  (8 ms)
 * Your runtime beats 88.14 % of cpp submissions
 * Your memory usage beats 45.34 % of cpp submissions (8.2 MB)
 */
class Solution {
public:
    bool isValid(string s) {
        array<int, 20001> st;
        uint32_t ptr = 0;
        for (auto& c : s) {
            if ('c' != c) {
                st[ptr++] = c;
            } else {
                if (ptr && 'b' == st[ptr - 1]) {
                    --ptr;
                    if (ptr && 'a' == st[ptr - 1]) {
                        --ptr;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return !ptr;
    }
};
// @lc code=end
/*
"aaabc"\n
"aabbcc"\n
"aabcbc"\n
"abcabcababcc"\n
"abccba"\n
"bac"\n
*/