/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-06
 * 87/87 (36 ms)
 * Your runtime beats 86.05 % of cpp submissions
 * Your memory usage beats 45.8 % of cpp submissions (21.5 MB)
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> pos_cnt;
        for (auto& lev : wall) {
            int i = 0;
            int j = 0;
            for (auto n : lev) {
                j++;
                if (j == lev.size()) {
                    break;
                }
                i += n;
                pos_cnt[i]++;
            }
        }
        size_t res = wall.size();
        for (auto it = pos_cnt.begin(); it != pos_cnt.end(); it++) {
            res = min(res, wall.size() - (*it).second);
        }
        return res;
    }
};
// @lc code=end

