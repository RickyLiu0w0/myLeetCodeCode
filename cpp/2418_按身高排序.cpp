/*
 * @lc app=leetcode.cn id=2418 lang=cpp
 *
 * [2418] 按身高排序
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-25
 * 68/68 (32 ms)
 * Your runtime beats 72.76 % of cpp submissions
 * Your memory usage beats 62.16 % of cpp submissions (20 MB)
*/
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>> v;
        vector<string> res;

        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            v.emplace_back(make_pair(heights[i], i));
        }

        sort(v.begin(), v.end(), [](pair<int, int>&a, pair<int, int>&b) -> bool {
            return a.first > b.first;
        });

        for (int i = 0; i < n; ++i) {
            res.emplace_back(names[v[i].second]);
        }

        return res;
    }
};
// @lc code=end

