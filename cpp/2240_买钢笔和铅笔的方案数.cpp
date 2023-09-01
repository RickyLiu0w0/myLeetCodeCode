/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 *
 * [2240] 买钢笔和铅笔的方案数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-00-01
 * 145/145 (12 ms)
 * Your runtime beats 82.31 % of cpp submissions
 * Your memory usage beats 27.21 % of cpp submissions (5.9 MB)
*/
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int max_pen = total / cost1;
        long long res = 0;
        for (int p = 0; p <= max_pen; ++p) {
            res += 1 + (total - p * cost1) / cost2;
        }
        return res;
    }
};
// @lc code=end

/*
20\n10\n5\n
5\n10\n10\n
1000000\n1\n1
*/