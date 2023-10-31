/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-09
 * 3999/3999 (16 ms)
 * Your runtime beats 47.08 % of cpp submissions
 * Your memory usage beats 22.91 % of cpp submissions (8 MB)
 */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> ma;
        ma['I'] = 1;
        ma['V'] = 5;
        ma['X'] = 10;
        ma['L'] = 50;
        ma['C'] = 100;
        ma['D'] = 500;
        ma['M'] = 1000;

        int ptr = 0, n = s.length();
        int res = 0;
        while (ptr < n) {
            char c = s[ptr];
            switch (c) {
                case 'I':
                    // 向前探测一下
                    if (ptr + 1 < n && (s[ptr + 1] == 'V' || s[ptr + 1] == 'X')) {
                        // IV或者IX
                        ++ptr;
                        res += (s[ptr] == 'V') ? 4 : 9;
                    } else {
                        res += 1;
                    }
                    break;
                case 'X':
                    // 向前探测一下
                    if (ptr + 1 < n && (s[ptr + 1] == 'L' || s[ptr + 1] == 'C')) {
                        // XL或者XC
                        ++ptr;
                        res += (s[ptr] == 'L') ? 40 : 90;
                    } else {
                        res += 10;
                    }
                    break;
                case 'C':
                    // 向前探测一下
                    if (ptr + 1 < n && (s[ptr + 1] == 'D' || s[ptr + 1] == 'M')) {
                        // CD或者CM
                        ++ptr;
                        res += (s[ptr] == 'D') ? 400 : 900;
                    } else {
                        res += 100;
                    }
                    break;

                default:
                    res += ma[c];
                    break;
            }
            ++ptr;
        }
        return res;
    }
};
// @lc code=end

/*
"III"\n
"IV"\n
"IX"\n
"LVIII"\n
"MCMXCIV"
*/