/*
 * @lc app=leetcode.cn id=2651 lang=cpp
 *
 * [2651] 计算列车到站时间
 */

// @lc code=start
/**
 * Accepted 2023-09-08
 * 556/556 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 18.48 % of cpp submissions (5.9 MB)
*/
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
// @lc code=end

