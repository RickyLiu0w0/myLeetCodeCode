/*
 * @lc app=leetcode.cn id=1499 lang=cpp
 *
 * [1499] 满足不等式的最大值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-26
 * 66/66 (308 ms)
 * Your runtime beats 23.08 % of cpp submissions
 * Your memory usage beats 36.26 % of cpp submissions (90.1 MB)
*/
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        /* 优先队列解法 */
        /**
         * yi + yj + |xi - xj| 若 i < j
         * yi + yj - (xi - xj)
         * yj + xj + yi - xi 要最大化，先把yi - xi以优先队列的形式
         * 为了确保i < j，先用xj访问队列中的xi，再将xj加入队列中成为xi
         * 如果xj - xi 已经大于k，则出队，直到队为空
         * 这里用了一个性质，由于xj是单调递增的，如果当前xj与xi距离大于k，则后面的xj更会远离
         */
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> heap; // pair<yi-xi, xi>
        int res = INT_MIN;
        for (auto& point : points) {
            int xj = point[0];
            int yj = point[1];
            while (!heap.empty() && xj - heap.top().second > k) {
                // 都是不符合的节点，弹出
                heap.pop();
            }
            if (!heap.empty()) {
                int yiMinusXi = heap.top().first;
                res = max(res, yiMinusXi + xj + yj);
            }
            heap.emplace(yj - xj, xj);
        }
        return res;
    }
};
// @lc code=end

