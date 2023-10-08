/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-10
 * 45/45 (92 ms)
 * Your runtime beats 5.3 % of cpp submissions
 * Your memory usage beats 5.03 % of cpp submissions (82.4 MB)
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> grid(numCourses, vector<int>(numCourses, 0));
        unordered_map<int, int> ma; // <课程，前序依赖>
        for (auto prerequisity : prerequisites) {
            grid[prerequisity[1]][prerequisity[0]] = 1;
            ma[prerequisity[0]]++;
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        bool res = true;
        vector<int> path;
        function<void(int)> dfs = [&](int i) {
            if (onPath[i]) {
                res = false;
                return;
            }

            if (ma[i]) {
                return;
            }

            if (!res || visited[i]) {
                return;
            }

            path.emplace_back(i);
            visited[i] = true;
            onPath[i] = true;

            for (int j = 0; j < numCourses; ++j) {
                if (grid[i][j]) {
                    ma[j]--;
                    dfs(j);
                }
            }

            onPath.at(i) = false;
        };

        for (int i = 0; i < numCourses; ++i) {
            dfs(i);
        }

        return path.size() == numCourses ? path : vector<int>();
    }
};
// @lc code=end

/*
2\n[[1,0]]\n
4\n[[1,0],[2,0],[3,1],[3,2]]\n
1\n[]\n
3\n[[1,0],[1,2],[0,1]]
*/