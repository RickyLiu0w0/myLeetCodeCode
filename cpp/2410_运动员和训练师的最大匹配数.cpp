/*
 * @lc app=leetcode.cn id=2410 lang=cpp
 *
 * [2410] 运动员和训练师的最大匹配数
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-09-28
    35/35 (148 ms)
    Your runtime beats 43.44 % of cpp submissions
    Your memory usage beats 25.11 % of cpp submissions (74.7 MB)
*/
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        uint32_t p = 0, t = 0;
        int res = 0;

        uint32_t pSize = players.size(), tSize = trainers.size();

        while (pSize != p && tSize != t) {
            if (players[p] <= trainers[t]) {
                ++res;
                ++p;
            }

            ++t;
        }
        return res;
    }
};
// @lc code=end
