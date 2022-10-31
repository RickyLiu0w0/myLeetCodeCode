/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] 灯泡开关 Ⅱ
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-09-15
 * 80/80 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 58.97 % of cpp submissions (5.8 MB)
 */
class Solution {
public:
    int flipLights(int n, int presses) {
        int res[4] = {1, 4, 7, 8};
        presses = presses > 3 ? 3 : presses;

        if (n > 3) {
            return res[presses];
        } else {
            if (presses == n - 1) {
                return pow(2, n) - 1;
            } else {
                return res[presses] > pow(2, n) ? pow(2, n) : res[presses];
            }
        }
    }
};
// @lc code=end
