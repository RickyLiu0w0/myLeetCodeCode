/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 *
 * [2050] 并行课程 III
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-28
 * 42/42 (316 ms)
 * Your runtime beats 95.74 % of cpp submissions
 * Your memory usage beats 55.32 % of cpp submissions (129.3 MB)
*/
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> dependency_array(n + 1);  // 当前节点的后续节点
        vector<int> dependency_count(n + 1, 0);       // 当前节点有多少个前节点
        vector<int> begin_time(n + 1, 0);
        vector<int> end_time(n + 1, 0);

        // 构造依赖
        for (auto& relation : relations) {
            dependency_array[relation[0]].emplace_back(relation[1]);
            dependency_count[relation[1]]++;
        }
        queue<int> can_schedule;

        for (int i = 1; i <= n; ++i) {
            if (dependency_count[i] == 0) {
                can_schedule.push(i);
            }
        }

        while (!can_schedule.empty()) {
            int clz = can_schedule.front();
            can_schedule.pop();
            end_time[clz] = begin_time[clz] + time[clz - 1];

            for (int clzz : dependency_array[clz]) {
                dependency_count[clzz]--;
                begin_time[clzz] = max(begin_time[clzz], end_time[clz]); // 最早开始和受依赖结束的最大值
                if (dependency_count[clzz] == 0) {
                    can_schedule.push(clzz);
                }
            }
        }

        return *max_element(end_time.begin(), end_time.end());
    }
};
// @lc code=end

/*
9\n
[[2,7],[2,6],[3,6],[4,6],[7,6],[2,1],[3,1],[4,1],[6,1],[7,1],[3,8],[5,8],[7,8],[1,9],[2,9],[6,9],[7,9]]\n[9,5,9,5,8,7,7,8,4]\n
3\n[[1,3],[2,3]]\n[3,2,5]
*/