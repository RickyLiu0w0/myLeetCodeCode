/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-01
 * 40/40 (112 ms)
 * Your runtime beats 81.89 % of cpp submissions
 * Your memory usage beats 30.37 % of cpp submissions (125.2 MB)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 计算经过这个站点后油量的总变化，并记录最经过某一个站点后最小的油
        int sum = 0, min_sum = 0, res = 0;
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < min_sum) {
                // 找到最低点
                min_sum = sum;
                res = i + 1;
            }
        }
        if (sum < 0) {
            // 总gas小于总cost
            return -1;
        }

        return res == n ? 0 : res;
    }
};
// @lc code=end

