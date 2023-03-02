/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include "AllInclude.h"

/**
 * Accepted 2023-03-01
 * 39/39 (384 ms)
 * Your runtime beats 5.18 % of cpp submissions
 * Your memory usage beats 41.35 % of cpp submissions (44.4 MB)
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  // 升序排列，最顶为最小值
        for (auto& num : nums) {
            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }

private:
    void quick_sort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int pos = partiton(nums, left, right);
        quick_sort(nums, left, pos - 1);
        quick_sort(nums, pos + 1, right);
        return;
    }

    int partiton(vector<int>& nums, int left, int right) {
        int val = nums.at(left);
        while (left < right) {
            while (left < right && val <= nums.at(right)) {
                --right;
            }

            nums[left] = nums[right];  // 将比val小的放在左边

            while (left < right && val >= nums.at(left)) {
                ++left;
            }

            nums[right] = nums[left];  // 比val大的放右边
        }
        nums[left] = val;
        return left;
    }
};
// @lc code=end
/*
[3,2,1,5,6,4]\n2\n
[3,2,3,1,2,4,5,5,6]\n4
*/