/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-07-02 15:38
 * 198/198 (84 ms)
 * Your runtime beats 40.81 % of cpp submissions
 * Your memory usage beats 65.81 % of cpp submissions (15.8 MB)
 */
class Solution {
public:
    int minRefuelStopsOffical(int target, int startFuel,
                              vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans = 0, prev = 0, fuel = startFuel;
        int n = stations.size();
        for (int i = 0; i <= n; i++) {
            int curr = i < n ? stations[i][0] : target;
            fuel -= curr - prev;
            while (fuel < 0 && !pq.empty()) {
                fuel += pq.top();
                pq.pop();
                ans++;
            }
            if (fuel < 0) {
                return -1;
            }
            if (i < n) {
                pq.emplace(stations[i][1]);
                prev = curr;
            }
        }
        return ans;
    }

    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        /**
         * 题目从最少加油次数转变求第j次加油，能跑最长的距离
         * d[j]的含义是从出发开始加了j次油，可以行走的最远距离
         * 若dp[i] >= target 则可以跑到目的地，i就是答案
         */

        uint16_t stationNum = stations.size();
        // int dp[stationNum];
        // memset(dp, 0, sizeof(dp));
        long long* dp = (long long*)calloc(stationNum + 1, sizeof(long long));
        dp[0] = startFuel;
        // 循环每个加油站看加了这个加油站的油之后(j+1)最远可以走多少
        for (uint16_t i = 0; i < stationNum; ++i) {
            for (uint16_t j = i; ; --j) {
                if (dp[j] >= stations[i][0]) {
                    // 从出发点加了第j次油之后可以到达地i个加油站
                    // 不加：dp[j+1]；加：dp[j] + stations[i][1]
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }

                if(!j) break;
            }
        }

        for (uint16_t i = 0; i < stationNum + 1; ++i) {
            if (dp[i] >= target)
                return i;
        }

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
[[13,21],[26,115],[225,99],[400,198],[408,290]]\n
1000000000\n
1000000000\n
[[5,1000000000],[1000,1000000000],[100000,1000000000]]
*/