/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-25
 * 49/49 (112 ms)
 * Your runtime beats 34.2 % of cpp submissions
 * Your memory usage beats 24.35 % of cpp submissions (41 MB)
*/
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 用两个hashMap存X、Y方向上的障碍物，然后用模拟一步一步的办法判断是否是障碍物
        unordered_map<int, unordered_set<int>*> x_obstacles;
        for (auto& obstacle : obstacles) {
            int x = obstacle[0];
            int y = obstacle[1];
            if (x_obstacles.count(x)) {
                x_obstacles.at(x)->insert(y);
            } else {
                x_obstacles.emplace(make_pair(x, new unordered_set<int>{y}));
            }
        }

        //                                     上       右      下        左
        const pair<int, int> direction[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currentDirection = 0;
        function<void(bool)> changeDirection = [&currentDirection](bool cmd) {
            // cmd == true 为向右转
            switch(currentDirection) {
                case 0:
                    currentDirection = cmd ? 1 : 3;
                    break;
                case 1:
                    currentDirection = cmd ? 2 : 0;
                    break;
                case 2:
                    currentDirection = cmd ? 3 : 1;
                    break;
                default:
                    // 3 
                    currentDirection = cmd ? 0 : 2;
                    break;
            }
        };

        // 开始模拟
        pair<int, int> pos{0,0};
        function<bool()> hasobstacle = [&]() -> bool {
            // cout << "query (" << pos.first << "," << pos.second << ")\n";
            if (x_obstacles.count(pos.first)) {
                return x_obstacles.at(pos.first)->count(pos.second);
            }
            return false;
        };
        int res = 0;
        for (auto cmd : commands) {
            if (cmd < 0) {
                changeDirection(cmd == -1);
                continue;
            }
            while (cmd--) {
                pos.first += direction[currentDirection].first;
                pos.second += direction[currentDirection].second;
                if (hasobstacle()) {
                    pos.first -= direction[currentDirection].first;
                    pos.second -= direction[currentDirection].second;
                    break;
                }
            }
            res = max(res, (int)(pow(pos.first, 2) + pow(pos.second, 2)));
        }
        return res;
    }
};
// @lc code=end

