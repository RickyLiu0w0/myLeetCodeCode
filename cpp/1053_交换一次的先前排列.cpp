/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-03
 * 54/54 (16 ms)
 * Your runtime beats 92.09 % of cpp submissions
 * Your memory usage beats 22.3 % of cpp submissions (24.1 MB)
*/
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        // 先找第一个逆序，即arr[i] > arr[i + 1]
        // 再从最右找第一个比arr[i]小的arr[j]交换，因为arr[i]的右边保证有一个数小于arr[i]（就是arr[i + 1]这个数）
        // 所以j不会小于i

        int n = arr.size();

        for (int i = n - 2; i > -1; --i) {
            if (arr[i] > arr[i + 1]) {
                int j = n - 1;
                while (arr[j - 1] == arr[j] || arr[i] <= arr[j]) {
                    // 要把右边小的交换，所以大于等于arr[i]的不要
                    j--;
                }
                // 最差也会有 j == i + 1
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};
// @lc code=end

