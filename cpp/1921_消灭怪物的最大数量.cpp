/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 *
 * [1921] 消灭怪物的最大数量
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-03
 * 131/131 (128 ms)
 * Your runtime beats 47.17 % of cpp submissions
 * Your memory usage beats 100 % of cpp submissions (79 MB)
*/
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // 转变为时间
        int n = dist.size();
        for (int i = 0; i < n; ++i) {
            // 向上取整
            dist[i] = (dist[i] - 1) / speed[i] + 1;
        }
        sort(dist.begin(), dist.end());

        for (int i = 1; i < n; ++i) {
            if (dist[i] > i) {
                continue;
            }
            return i;
        }
        return n;
    }
};
// @lc code=end

/*
[1,3,4]\n[1,1,1]\n
[1,1,2,3]\n[1,1,1,1]\n
[3,2,4]\n[5,3,2]\n
[1,2,3,4,5,6,7,8]\n[8,7,6,5,4,3,2,1]\n
[2,4,6,8,10,12,14,16]\n[1,2,3,4,5,6,7,8]\n
[3,5,7,4,5]\n[2,3,6,3,2]
*/