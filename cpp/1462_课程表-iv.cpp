/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-12
 * 68/68 (300 ms)
 * Your runtime beats 22.01 % of cpp submissions
 * Your memory usage beats 89.19 % of cpp submissions (57.8 MB)
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // can_arrive[i][j]说明可以从i溯源到j
        vector<vector<bool>> can_arrive(numCourses, vector<bool>(numCourses, false));
        for (auto& course : prerequisites) {
            can_arrive[course[1]][course[0]] = true;
        }

        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (!can_arrive[i][j])
                        // 从i到k，再从k到j
                        can_arrive[i][j] = (can_arrive[i][k] && can_arrive[k][j]);
                }
            }
        }
        vector<bool> res;
        for (auto& course : queries) {
            res.emplace_back(can_arrive[course[1]][course[0]]);
        }
        return res;
    }
};
// @lc code=end

/*
2\n[[1,0]]\n[[0,1],[1,0]]\n
2\n[]\n[[1,0],[0,1]]\n
3\n[[1,2],[1,0],[2,0]]\n[[1,0],[1,2]]\n
5\n[[0,1],[1,2],[2,3],[3,4]]\n[[0,4],[4,0],[1,3],[3,0]]
*/