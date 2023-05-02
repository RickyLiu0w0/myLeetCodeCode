/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-05-02
 * 104/104 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 63.75 % of cpp submissions (6.4 MB)
*/
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;

        int val1 = 1;
        for (int i = 0; i < 21; ++i) {
            int val2 = 1;
            for (int j = 0; j < 21; ++j) {
                int res = val1 + val2;
                if (res > bound) {
                    break;
                }
                s.insert(res);
                val2 *= y;
            }
            if (val1 > bound) {
                break;
            }
            val1 *= x;
        }

        return vector<int>(s.begin(), s.end());
    }
};
// @lc code=end

