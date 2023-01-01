/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-28
 * 87/87 (56 ms)
 * Your runtime beats 98.22 % of cpp submissions
 * Your memory usage beats 99.24 % of cpp submissions (37.9 MB)
*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        uint64_t res = 0;
        size_t stack[30001]; // 存数组下标
        int sPtr = -1, size = arr.size() + 1;

        for (size_t i = 0; i < size; ++i) {
            int num = 0;
            if (i < size - 1) {
                num = arr[i];
            }

            while (sPtr != -1 && arr[stack[sPtr]] > num) {
                // num的辐射范围(L, R)开区间，num在M这个索引上
                // res = num * (R - M) * (M - L)
                res += (i - stack[sPtr]) * (stack[sPtr] - (sPtr ? stack[sPtr - 1] : -1)) * arr[stack[sPtr]];
                --sPtr;
            }

            stack[++sPtr] = i;
        }
        
        return res % 1000000007;
    }
};
// @lc code=end
