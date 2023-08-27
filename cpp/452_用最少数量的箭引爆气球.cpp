/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-26
 * 50/50 (456 ms)
 * Your runtime beats 27.55 % of cpp submissions
 * Your memory usage beats 72.15 % of cpp submissions (87.6 MB)
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 直接用贪心法试试
        sort(points.begin(), points.end());
        int n = points.size(), res = n, i = 1, end = points[0][1];
        while (i < n) {
            if (points[i][0] <= end) {
                // 有交集
                --res;
                end = min(end, points[i][1]);
            } else {
                end = points[i][1];
            }
            ++i;
        }

        return res;
    }
};
// @lc code=end

/*
[[10,16],[2,8],[1,6],[7,12]]\n
[[1,2],[3,4],[5,6],[7,8]]\n
[[1,2],[2,3],[3,4],[4,5]]\n
[[1,2],[1,4]]\n
[[1,10], [2,9]]\n
[[1,2],[4,5],[1,5]]\n
[[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]
*/