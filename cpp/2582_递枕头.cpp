/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-26
 * 68/68 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 10.9 % of cpp submissions (6.1 MB)
*/
class Solution {
public:
    int passThePillow(int n, int time) {
        int res = 1;
        bool left = true;
        while (time--) {
            if (left) {
                if (res == n) {
                    res = n - 1;
                    left = false;
                } else {
                    res++;
                }
            } else {
                if (res == 1) {
                    res = 2;
                    left = true;
                } else {
                    res--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

