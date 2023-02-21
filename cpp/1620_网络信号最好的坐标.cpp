/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-11-01
 * 100/100 (64 ms)
 * Your runtime beats 43.53 % of cpp submissions
 * Your memory usage beats 34.12 % of cpp submissions (8.6 MB)
 */
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        uint8_t xMin = UINT8_MAX, xMax = 0;
        uint8_t yMin = UINT8_MAX, yMax = 0;
        for (auto& tower : towers) {
            if (tower[0] > xMax) {
                xMax = tower[0];
            }

            if (xMin > radius && tower[0] < xMin) {
                xMin = tower[0];
            }

            if (tower[1] > yMax) {
                yMax = tower[1];
            }

            if (yMin > radius && tower[1] < yMin) {
                yMin = tower[1];
            }
        }

        xMax += radius;
        yMax += radius;

        // 保证非负坐标
        xMin = xMin > radius ? xMin - radius : 0;
        yMin = yMin > radius ? yMin - radius : 0;

        int max_signal = 0;
        int max_signal_x = 0;
        int max_signal_y = 0;
        int radius_pow = pow(radius, 2);
        for (int x = xMin; x <= xMax; ++x) {
            for (int y = yMin; y <= yMax; ++y) {
                int signal = 0;
                for (auto& tower : towers) {
                    double d_pow = pow(x - tower[0], 2) + pow(y - tower[1], 2);
                    if (d_pow > radius_pow) {
                        continue;
                    }
                    signal += tower[2] / (1 + sqrt(d_pow));
                }

                if (signal > max_signal) {
                    max_signal = signal;
                    max_signal_x = x;
                    max_signal_y = y;
                }
            }
        }

        return vector<int>{max_signal_x, max_signal_y};
    }
};
// @lc code=end
