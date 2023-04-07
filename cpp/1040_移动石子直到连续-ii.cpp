/*
 * @lc app=leetcode.cn id=1040 lang=cpp
 *
 * [1040] 移动石子直到连续 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-07
 * 26/26 cases passed (16 ms)
 * Your runtime beats 93.75 % of cpp submissions
 * Your memory usage beats 20 % of cpp submissions (12.9 MB)
*/
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        vector<int>& s = stones;
        sort(s.begin(), s.end());

        int n = s.size();
        // 把前面的往后挪
        // 在(1, n-1)中，应该有s[n-1] - s[1] - 1个数，现在已存在(n - 3)个数
        // 空位数量（需补充，还差） s[n-1] - s[1] - 1 - (n - 3) 个数
        int res1 = s[n - 1] - s[1] + 2 - n;

        // 把后面的往前挪
        // 空位数量 s[n-2] - s[0] - 1 - (n - 3)
        int res2 = s[n - 2] - s[0] + 2 - n;
        int max_res = max(res1, res2);

        if (!res1 || !res2) {
            // 有一边是排紧凑了
            return {min(2, max_res), max_res};
        }

        int min_res = 0, left = 0, right = 0;

        while (right < n) {
            // 这个双指针是寻找数字的最大窗口
            // 窗口内部一定满足s[right] - s[left] + 1 <= n
            while (s[right] - s[left] + 1 > n) {
                ++left;
            }
            min_res = max(min_res, right - left + 1);
            ++right;
        }
        return {n - min_res, max_res};
    }
};
// @lc code=end

