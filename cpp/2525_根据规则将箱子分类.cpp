/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 *
 * [2525] 根据规则将箱子分类
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-20
 * 50/50 (4 ms)
 * Your runtime beats 17.99 % of cpp submissions
 * Your memory usage beats 22.3 % of cpp submissions (6.2 MB)
*/
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool Bulky = (length >= 1e4 || width >= 1e4 || height >= 1e4) || ((long long)length * height * width >= 1e9);
        bool heavy = mass >= 100;
        if (heavy && Bulky) {
            return "Both";
        }
        if (!heavy && !Bulky) {
            return "Neither";
        }
        if (heavy) {
            return "Heavy";
        }
        return "Bulky";
    }
};
// @lc code=end

