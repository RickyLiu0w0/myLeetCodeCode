/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-22
 * 149/149 (136 ms)
 * Your runtime beats 75.88 % of cpp submissions
 * Your memory usage beats 26.47 % of cpp submissions (19.4 MB)
*/
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> vp;
        size_t n = scores.size();
        for (size_t i = 0; i < n; ++i) {
            vp.emplace_back(make_pair(scores.at(i), ages.at(i)));
        }

        sort(vp.begin(), vp.end(), [](pair<int, int>& x, pair<int, int>& y) -> bool {
            // 分数优先，年龄随后
            if (x.first < y.first) {
                return true;
            } else if (x.first > y.first) {
                return false;
            } else {
                return x.second < y.second;
            }
        });

        vector<int> dp(n, 0);

        int res = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (vp[j].second <= vp[i].second) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += vp[i].first;
            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end

/*
[319776,611683,835240,602298,430007,574,142444,858606,734364,896074]\n[1,1,1,1,1,1,1,1,1,1]\n
[1,1,1,1,1,1,1,1,1,1]\n[811,364,124,873,790,656,581,446,885,134]\n
[1,3,7,3,2,4,10,7,5]\n[4,5,2,1,1,2,4,1,4]
*/
