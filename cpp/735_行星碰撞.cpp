/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-07-13 19:18
 * 275/275 (152 ms)
 * Your runtime beats 7.93 % of cpp submissions
 * Your memory usage beats 53.96 % of cpp submissions (17.1 MB)
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool clean;

        while (1) {
            // 扫描asteroids数组，判断是否存在爆炸问题
            // int asteroidSize = asteroids.size();
            clean = true;
            for (int i = 0; i < int(asteroids.size()) - 1; ++i) {
                if (asteroids[i] > 0 && asteroids[i + 1] < 0) {
                    // 存在碰撞
                    clean = false;
                    if (asteroids[i] > abs(asteroids[i + 1])) {
                        // 留下前面的星球
                        asteroids.erase(asteroids.begin() + i + 1);
                    } else if (asteroids[i] == abs(asteroids[i + 1])) {
                        asteroids.erase(asteroids.begin() + i);
                        asteroids.erase(asteroids.begin() + i);
                    } else {
                        // 留下后面的星球
                        asteroids.erase(asteroids.begin() + i);
                    }
                    --i;
                }
            }

            if (clean) {
                return asteroids;
            }
        }

        return vector<int>{};
    }
};
// @lc code=end

/*
[5,10,-5]\n
[8,-8]\n
[8,1,-8]\n
[10,2,-5]\n
[10,9,8,1,-8,-8,2,3,4,-6,10,-9,9,-9]\n
[1,-1,-2,-2]
*/