/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-22
 * 30/30 (72 ms)
 * Your runtime beats 96.79 % of cpp submissions
 * Your memory usage beats 76.93 % of cpp submissions (48.4 MB)
*/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int, 3>> jobs;
        size_t jobSize = startTime.size();
        for (size_t i = 0; i < jobSize; ++i) {
            jobs.emplace_back(array<int, 3>{startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](array<int, 3>& a, array<int, 3>& b) -> bool { return a[1] < b[1]; });

        vector<int> dp(jobSize);
        dp[0] = jobs[0][2];
        for (size_t i = 1; i < jobSize; ++i) {
            int totalProfit = jobs[i][2];
            for (int j = i - 1; j > -1; --j) {
                // 找到一个能拼合的工作
                if (jobs[j][1] <= jobs[i][0]) {
                    // j 工作结束时间小于等于i工作开始时间，能拼
                    totalProfit += dp[j];
                    break;
                }
            }

            dp[i] = max(dp[i - 1], totalProfit);
        }
        return dp[jobSize - 1];
    }
};
// @lc code=end
/*
[1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]\n
[1,2,3,4,6]\n[3,5,10,6,9]\n[20,20,100,70,60]\n
[1,1,1]\n[2,3,4]\n[5,6,4]
*/