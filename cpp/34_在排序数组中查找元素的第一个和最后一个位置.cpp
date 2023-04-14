/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-14
 * 88/88 (8 ms)
 * Your runtime beats 62.59 % of cpp submissions
 * Your memory usage beats 31.26 % of cpp submissions (13.3 MB)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        auto f1 = [&](int t) -> int {
            int l = 0, r = n - 1;

            // 闭区间[l, r]，则有l - 1 都是 < target 的；r + 1都是 >= target 的
            while (l <= r) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] < t) {
                    // 保证l - 1都是这个条件
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return l; // 此时 l == r + 1
        };

        auto f2 = [&](int t) {
            int l = 0, r = n;

            // 左闭右开区间，[l, r)，则有l - 1 都是 < target；r都是 >= target 的
            while (l < r) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] < t) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l; // 此时 l == r
            // return r; // 也行
        };

        auto f3 = [&](int t) {
            int l = -1, r = n;

            // 左开右开区间，(l, r)，则有l都是 < target；r都是 >= target 的
            while (l + 1 < r) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] < t) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            return r; // l + 1 == r
        };
        
        int low = f3(target);
        if (low == n || nums[low] != target) {
            return {-1, -1};
        }

        int high = f3(target + 1) -1 ;
        return {low, high};
    }
};
// @lc code=end

