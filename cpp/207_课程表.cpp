/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-30
 * 52/52 (80 ms)
 * Your runtime beats 5.24 % of cpp submissions
 * Your memory usage beats 6.71 % of cpp submissions (15.5 MB)
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 就是判定有没有环
        // 邻接矩阵
        vector<vector<bool>> grid(numCourses, vector<bool>(numCourses, false));
        for (auto& v : prerequisites) {
            grid[v[1]][v[0]] = true;
        }

        bool res = true;
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        function<void(int)> dfs = [&](int clz) {
            if (path[clz]) {
                res = false;
            }

            if (!res || visited[clz]) {
                return;
            }

            path[clz] = true;
            visited[clz] = true;
            // cout << clz << " visited\n";
            for (int i = 0; i < numCourses; ++i) {
                 // cout << "grid[" << clz << "][" << i << "]=" << grid[clz][i] << endl;
                if (grid[clz][i]) {
                    dfs(i);
                }
            }
            path[clz] = false;
        };
        for (int i = 0; i < numCourses && res ; ++i) {
            dfs(i);
        }
        return res;
    }
};
// @lc code=end

/*
2000\n[]\n
2\n[[1,0]]\n
2\n[[0,1], [1,0]]\n
2\n[[1,0],[0,1]]\n
5\n[[1,4],[2,4],[3,1],[3,2]]
*/