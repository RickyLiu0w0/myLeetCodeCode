/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-10
 * 75/75 (4 ms)
 * Your runtime beats 85.99 % of cpp submissions
 * Your memory usage beats 54.96 % of cpp submissions (8.8 MB)
 */
class Solution {
public:
    int compress(vector<char>& chars) {
        // 双指针
        int res_ptr = 0, char_ptr = 0, n = chars.size();

        while (char_ptr < n) {
            char c = chars[char_ptr];
            int base = char_ptr;
            while (char_ptr < n && c == chars[char_ptr]) {
                ++char_ptr;
            }
            int num = char_ptr - base;
            chars[res_ptr++] = c;
            base = res_ptr;
            if (num > 1) {
                while (num) {
                    chars[res_ptr++] = (num % 10) + '0';
                    num /= 10;  
                }
                reverse(chars.begin() + base, chars.begin() + res_ptr);
            }
        }
       
        return res_ptr;
    }
};
// @lc code=end

