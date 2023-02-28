/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */


/**
 * Accepted 2023-02-28
 * 211/211 (148 ms)
 * Your runtime beats 17.21 % of cpp submissions
 * Your memory usage beats 57.09 % of cpp submissions (91.1 MB)
*/

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price = prices.at(0), res = 0;

        for (auto & price : prices) {

            if (price < min_price) {
                min_price = price;
            }
            res = std::max(res, price - min_price);
        }

        return res;
    }
};
// @lc code=end

