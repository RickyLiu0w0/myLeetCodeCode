/*
 * @lc app=leetcode.cn id=822 lang=cpp
 *
 * [822] 翻转卡片游戏
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-02
 * 169/169 (16 ms)
 * Your runtime beats 73.74 % of cpp submissions
 * Your memory usage beats 31.31 % of cpp submissions (19 MB)
*/
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        int res = INT_MAX;
        set<int> forbidden;
        for (int i = 0; i < n; ++i) {
            int f = fronts[i];
            int b = backs[i];
            if (f == b) {
                // 这个数字被禁止
                forbidden.insert(f);
            }
        }

        for (int num : fronts) {
            if (forbidden.find(num) == forbidden.end())
                res = min(res, num);
        }

        for (int num : backs) {
            if (forbidden.find(num) == forbidden.end())
                res = min(res, num);
        }

        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

/*
[1]\n[1]\n
[2,2]\n[1,3]\n
[1,3,5]\n[2,2,1]\n
[2,2,2,3,3]\n[1,3,4,5,7]\n
[2,3,3]\n[4,3,3]\n
[1,1]\n[2,2]\n
[1,1]\n[1,2]
*/