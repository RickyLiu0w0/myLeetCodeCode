/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-27
 * 56/56 (64 ms)
 * Your runtime beats 62.83 % of cpp submissions
 * Your memory usage beats 30.97 % of cpp submissions (31.8 MB)
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int max_h = 0, max_w = 0, n = horizontalCuts.size();
        int first = 0, second = horizontalCuts.front(), i = 1;
        while (1) {
            max_h = max(max_h, second - first);
            first = second;
            if (i != n)
                second = horizontalCuts[i++];
            else
                break;
        }
        max_h = max(max_h, h - first);
        first = 0, second = verticalCuts.front(), n = verticalCuts.size(), i = 0;
        while (1) {
            max_w = max(max_w, second - first);
            first = second;
            if (i != n) {
                second = verticalCuts[i++];
            } else {
                break;
            }
        }
        max_w = max(max_w, w - first);
        return ((long long)max_h * (long long)max_w) % (int)(1e9 + 7);
    }
};
// @lc code=end

