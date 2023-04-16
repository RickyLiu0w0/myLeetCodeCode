/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

#include "AllInclude.h"

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) : s(nums.size() + 1, 0) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }

private:
    vector<int> s;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
