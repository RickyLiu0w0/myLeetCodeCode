/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-30
 * 306/306 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 49.13 % of cpp submissions (13 MB)
*/
const int DIR[8] = {-1, 0, 1, 0, 0, -1, 0, 1};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0, m = grid.size(), n = grid[0].size();
        int all_new = 0;
        int new_bad, now_bad = 2;
        // 现统计所有的好橘子
        for (auto& row : grid) {
            for (auto it : row) {
                if (it == 1) {
                    all_new++;
                }
            }
        }
        do {
            new_bad = 0; // 本轮新感染数
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == now_bad) {
                        // 是目前感染橘子
                        for (int k = 0; k < 4; ++k) {
                            int nxt_i = i + DIR[k*2];
                            int nxt_j = j + DIR[k*2+1];
                            if (nxt_i > -1 && nxt_i < m && nxt_j > -1 && nxt_j < n) {
                                if (grid[nxt_i][nxt_j] == 1) {
                                    // 是新鲜橘子，则感染
                                    grid[nxt_i][nxt_j] = now_bad + 1;
                                    new_bad++;
                                }
                            }
                        }
                    }
                }
            }
            all_new -= new_bad;
            now_bad++;
            minute++;
        } while (new_bad);
        return all_new == 0 ? minute - 1 : -1;
    }
};
// @lc code=end

