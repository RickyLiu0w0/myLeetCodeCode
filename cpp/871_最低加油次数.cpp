/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        /**
         * 题目从最少加油次数转变为到第i个加油站加满油的时候，能到达的最大距离
         * 当计算第i+1个加油站的时候，i的状态应被保留下来
         * 若dp[i] >= target 则可以跑到目的地，i就是答案
         */
        stations.insert(stations.begin(), vector<int>{0, startFuel});
        uint16_t stationNum = stations.size();
        int dp[stationNum], maxPath = 0, stepCount = 0;

        dp[0] = startFuel;
        uint16_t i = 0, j, maxIndex;
        while (i < stationNum) {
            maxIndex = i + 1;
            maxPath = 0;
            ++stepCount;
            for (j = i + 1; j < stationNum; ++j) {
                // 分析跑到后面加油站的情况
                // stations[j][0] - stations[i][0] 两给点之间的距离
                if (stations[j][0] - stations[i][0] > dp[i]) {
                    // 甚至跑不到下一个加油站
                    dp[j] = -1;
                    break;
                }

                // 开到第j加油站加满油可以走的最长路径
                dp[j] = dp[i] - (stations[j][0] - stations[i][0]) + stations[j][1];

                if (dp[j] > maxPath) {
                    if (dp[j] >= target - stations[j][0]) {
                        // 可以一路冲到终点
                        return stepCount;
                    }

                    // 找到更长的路
                    maxPath = dp[j];
                    maxIndex = j;  // 开到第j个加油站
                    cout << "i: " << i << " dp " << j << ": " << dp[j] << endl;
                }
            }

            i = maxIndex;
        }

        if (dp[stationNum - 1] >= target - stations[stationNum - 1][0])
            return stepCount - 1;
        else
            return -1;
    }
};
// @lc code=end

/*
1\n
1\n
[]\n
100\n
1\n
[[10,100]]\n
100\n
10\n
[[10,60],[20,30],[30,30],[60,40]]\n
100\n
10\n
[[1,20],[10,40],[40,40]]\n
700\n
299\n
[[13,21],[26,115],[225,99],[400,198],[408,290]]
*/

/*
vector<vector<int>> dp(stationNum + 1, vector<int>(stationNum + 1, -1));
        dp[0][0] = startFuel;

        if (dp[0][0] >= target)
            return 0;

        for (int i = 1; i <= stationNum; i++) {
            int max_pre = dp[i - 1][i - 1];
            if (max_pre == -1)
                return -1;
            for (int j = i; j <= stationNum; j++) {
                if (max_pre >= stations[j - 1][0]) {
                    dp[i][j] = max_pre + stations[j - 1][1];
                    if (dp[i][j] >= target)
                        return i;
                }
                if (max_pre < stations[j - 1][0] && dp[i - 1][j] == -1)
                    break;
                max_pre = max(max_pre, dp[i - 1][j]);
            }
        }
        return -1;
*/