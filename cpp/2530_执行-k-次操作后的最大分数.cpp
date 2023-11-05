/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-18
 * 39/39 (212 ms)
 * Your runtime beats 79.86 % of cpp submissions
 * Your memory usage beats 81.3 % of cpp submissions (71 MB)
*/
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(less<int>(), move(nums));
                
        long long sum = 0;
        while (k--) {
            int top = pq.top();
            sum += top;
            pq.pop();
            pq.push(ceil(top / 3.0));
        }

        return sum;
    }
};
// @lc code=end

