/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-29
 * 21/21 (16 ms)
 * Your runtime beats 50.29 % of cpp submissions
 * Your memory usage beats 5.09 % of cpp submissions (14.9 MB)
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num]++;
        }

        // 桶排序，桶的下标是频率，内容是该频率出现的内容
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [val, freq] : m) {
            bucket[freq].emplace_back(val);
        }

        vector<int> res;
        for (int i = nums.size(); i; --i) {
            if (bucket[i].empty()) {
                continue;
            }
            for (auto& num : bucket[i]) {
                res.emplace_back(num);
            
                if (!(--k)) {
                    return res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

