/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-02
 * 66/66 (4 ms)
 * Your runtime beats 33.33 % of cpp submissions
 * Your memory usage beats 7.14 % of cpp submissions (6.7 MB)
*/
class Solution {
public:
    int countPoints(string rings) {
        vector<bool> red(10, false);
        vector<bool> blue(10, false);
        vector<bool> green(10, false);
        int n = rings.length();
        for (int i = 0; i < n; i += 2) {
            if (rings[i] == 'B') {
                blue[rings[i + 1] - '0'] = true;
            } else if (rings[i] == 'R') {
                red[rings[i + 1] - '0'] = true;
            } else {
                green[rings[i + 1] - '0'] = true;
            }
        }
        int res = 0;
        for (int i = 0; i < 10; ++i) {
            if (red[i] && blue[i] && green[i]) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

