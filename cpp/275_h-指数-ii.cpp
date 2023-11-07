/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-30
 * 83/83 (16 ms)
 * Your runtime beats 58.94 % of cpp submissions
 * Your memory usage beats 32.76 % of cpp submissions (18.5 MB)
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 0 1 3 5 6
        // 5 4 3 2 1
        // 0 1 2 3 4
        int n = citations.size();
        int l = -1, r = n;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            if (citations[mid] < n - mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return n - r;
    }
};
// @lc code=end

/*
[0]\n
[1]\n
[2]\n
[1,2]\n
[1,2,3]\n
[1,2,4,5,6]\n
[1,1,3]\n
[1,3,3,3,3,3,3,3,4,5,6,7,8,9,10]\n
[11,15]\n
[1,2,10,11,15]
*/