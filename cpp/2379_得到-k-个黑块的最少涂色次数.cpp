/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

#include "AllInclude.h"

// @lc code=start

/**
 * Accepted 2023-03-09
 * 122/122 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 52.87 % of cpp submissions (6 MB)
 */

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w_counter = 0;
        size_t r = 0, size = blocks.length();
        // 统计[0, k) 窗口内的数
        for (; r < k; ++r) {
            if (blocks[r] == 'W') {
                ++w_counter;
            }
        }

        int res = w_counter;

        // 窗口往后移
        size_t l = 0;
        while (r < size) {
            if (blocks[r++] == 'W') {
                ++w_counter;
            }

            if (blocks[l++] == 'W') {
                --w_counter;
            }

            res = std::min(res, w_counter);
        }
        return res;
    }
};
// @lc code=end

/*
"WBBWWBBWBW"\n7\n
"WBWBBBW"\n2\n
"BBBBBBB"\n3\n
"WWWWWWW"\n5\n
"W"\n1\n
"B"\n1
*/
