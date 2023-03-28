/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-02-23
 * 118/118 (88 ms)
 * Your runtime beats 94.62 % of cpp submissions
 * Your memory usage beats 60.09 % of cpp submissions (65.2 MB)
*/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // 从右面开始找右边的严格递增，保证右边严格递增
        int size = arr.size();
        int r = size - 1;
        while (r > 0 && arr[r - 1] <= arr[r]) {
            --r;
        }

        if (!r) {
            return 0;
        }

        // 找到右边的最低点arr[r]，然后找左边的递增序列，保持和右递增序列衔接
        // 如何保持衔接？r++ 直到 arr[l] <= arr[r]
        int l = 0, res = r;
        while (l == 0 || arr[l - 1] <= arr[l]) {
            while (r < size && arr[l] > arr[r]) {
                r++;
            }
            res = min(res, r - l - 1);
            ++l;
        }
        return res;
    }
};
// @lc code=end

