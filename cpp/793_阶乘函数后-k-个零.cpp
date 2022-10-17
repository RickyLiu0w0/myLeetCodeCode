/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-08-28 15:03
 * 44/44 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 5.6 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    int preimageSizeFZF(int k) {
        return long(firstXInFx(k + 1) - firstXInFx(k));
    }

private:
    long firstXInFx(int k) {
        // 上界限
        long uppperBound = k * 5L;

        // 下界限
        long lowerBound = k * 4L;
        long x;

        while (lowerBound <= uppperBound) {
            long mid = (uppperBound - lowerBound) / 2 + lowerBound;
            if (f(mid) >= k) {
                uppperBound = mid - 1;
                x = mid;
            } else {
                lowerBound = mid + 1;
            }
        }

        return x;
    }

    int f(long x) {
        int res = 0;
        while (x) {
            x /= 5;
            res += x;
        }
        return res;
    }
};
// @lc code=end
