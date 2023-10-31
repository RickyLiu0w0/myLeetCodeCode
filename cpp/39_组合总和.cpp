/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-14
 * 160/160 (8 ms)
 * Your runtime beats 53.39 % of cpp submissions
 * Your memory usage beats 45 % of cpp submissions (10.9 MB)
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        this->tar = target;
        n = candidates.size();
        vector<int> path;
        backTrack(path, 0, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> candidates;
    int tar, n;
    void backTrack(vector<int>& path, int begin, int sum) {
        if (sum > tar) {
            // 由于都是正数，以及已经是无效的
            return;
        } else if (sum == tar) {
            // 有效
            res.emplace_back(path);
            return;
        }

        for (int i = begin; i < n; ++i) {
            path.emplace_back(candidates[i]); // 选择
            backTrack(path, i, sum + candidates[i]);
            path.pop_back(); // 撤销选择
        }
    }
};
// @lc code=end

