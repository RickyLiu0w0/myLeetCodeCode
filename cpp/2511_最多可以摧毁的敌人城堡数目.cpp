/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 *
 * [2511] 最多可以摧毁的敌人城堡数目
 */

#include "Allinclude.h"

// @lc code=start
/**
 * Accepted 2023-09-02
 * 45/45 (4 ms)
 * Your runtime beats 47.97 % of cpp submissions
 * Your memory usage beats 43.24 % of cpp submissions (7.6 MB)
 */
class Solution {
public:
    int captureForts(vector<int>& forts) {
        pair<int, int> p; // <最后一个特殊数字, 该数字的下标>
        int res = 0, n = forts.size();

        int i = 0;
        while (i < n && 0 == forts[i]) {
            ++i;
        }
        if (n == i) {
            return 0;
        }
        p.first = forts[i];
        p.second = i++;

        for (; i < n; ++i) {
            if (forts[i] == -1) {
                if (p.first == 1) {
                    // 可计算
                    res = max(res, i - p.second - 1);
                }
                p.first = -1;
                p.second = i;
            } else if (forts[i] == 1) {
                if (p.first == -1) {
                    // 可计算
                    res = max(res, i - p.second - 1);
                }
                p.first = 1;
                p.second = i;
            }
        }
    
        return res;
    }
};
// @lc code=end

/*
[1,0,0,-1,0,0,0,0,1]\n
[0,0,1,-1]\n
[1,0,0,-1,-1,1,0,0,0,1]\n
[0]\n
[1]\n
[-1]\n
[-1,1]\n
[-1,0,1]
*/