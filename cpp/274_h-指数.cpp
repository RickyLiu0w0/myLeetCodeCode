/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-04
 * 81/81 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 91.2 % of cpp submissions (8.3 MB)
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 0 1 3 5 6
        // 5 4 3 2 1
        // size() - i
        // 1 2 3 4 5

        // 1 1 3
        // 3 2 1
        sort(citations.begin(), citations.end());
        int n = citations.size(), h = 0;
        for (int i = n - 1; i > -1 && citations[i] > h; --i) {
            ++h;
        }
        return h;
    }
};
// @lc code=end

/*
[3,0,6,1,5]\n
[0]\n
[1]\n
[2]\n
[1,2]\n
[1,2,3]\n
[1,1,0]\n
[1,2,4,5,6]\n
[1,3,1]\n
[3,3,3,3,3,3,3,1,4,5,6,7,8,9,10]\n
[11,15]\n
[1,2,10,11,15]
*/