/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-02
 * 10/10 (4 ms)
 * Your runtime beats 47.09 % of cpp submissions
 * Your memory usage beats 68.15 % of cpp submissions (6.9 MB)
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, path, 0);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& path, size_t start) {
        size_t n = nums.size();
        res.emplace_back(path);
        for (size_t i = start; i < n; ++i) {
            path.emplace_back(nums.at(i));  // 做出选择
            backtrack(nums, path, i + 1);  // 递归进入下一层，注意i+1，标识下一个选择列表的开始位置，最重要的一步
            path.pop_back();  // 撤销选择
        }
        return;
    }
};
// @lc code=end
