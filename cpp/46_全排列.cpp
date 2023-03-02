/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-02
 * 26/26  (4 ms)
 * Your runtime beats 66.22 % of cpp submissions
 * Your memory usage beats 47.47 % of cpp submissions (7.7 MB)
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return res;
    }

private:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& track) {
        size_t n = nums.size();

        if (track.size() == n) {
            res.emplace_back(track);
            return;
        }

        for (size_t i = 0; i < n; ++i) {
            if (find(track.begin(), track.end(), nums.at(i)) != track.end()) {
                continue;
            }
            track.emplace_back(nums.at(i));
            backtrack(nums, track);
            track.pop_back();
        }
        return;
    }
};
// @lc code=end
