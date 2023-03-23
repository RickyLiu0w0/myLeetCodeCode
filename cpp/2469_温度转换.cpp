/*
 * @lc app=leetcode.cn id=2469 lang=cpp
 *
 * [2469] 温度转换
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-30-21
 * 74/74 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 12.66 % of cpp submissions (6 MB)
*/
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32.00};
    }
};
// @lc code=end

