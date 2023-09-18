/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-11
 * 97/97 (256 ms)
 * Your runtime beats 28.72 % of cpp submissions
 * Your memory usage beats 78.46 % of cpp submissions (54.8 MB)
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // 贪心法
        // 按照结束时间排序，完成先结束的课程
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] < b[1];
        });

        // 按持续时间从大到小排列的优先序列
        priority_queue<int> pq;
        int total = 0;
        for (auto& cou : courses) {
            total += cou[0];
            pq.push(cou[0]);
            if (total > cou[1]) {
                total -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
// @lc code=end

/*
[[7,16],[2,3],[3,12],[3,14],[10,19],[10,16],[6,8],[6,11],[3,13],[6,16]]\n
[[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]\n
[[1,2]]\n
[[3,2],[4,3]]
*/
