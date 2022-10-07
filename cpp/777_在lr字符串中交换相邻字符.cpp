/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        size_t s = 0, e = 0, size = start.length();
        while (s < size) {
            if (start[s] == 'X') {
                ++s;
                continue;
            }

            char temp = start[s];

            while (e < size) {
                if ('X' == end[e]) {
                    ++e;
                } else {
                    break;
                }
            }

            if (e == size || temp != end[e] || ('R' == temp && s > e) ||
                ('L' == temp && s < e)) {
                return false;
            }

            ++s;
            ++e;
        }

        while (e < size) {
            if ('X' != end[e]) {
                return false;
            }
            ++e;
        }
        return true;
    }
};
// @lc code=end
