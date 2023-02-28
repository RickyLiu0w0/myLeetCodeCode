/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

#include "AllInclude.h"

/**
 * Accepted 2023-02-27
 * 37/37 (4 ms)
 * Your runtime beats 35.11 % of cpp submissions
 * Your memory usage beats 46.81 % of cpp submissions (7 MB)
 */

// @lc code=start
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        size_t n = nums.size();
        if (1 == n) {
            return 0;
        }
        int res1 = 0, res2 = 0;
        // 处理A[0] > A[1] < A[2] > A[3] < A[4] > ...
        for (size_t i = 1; i < n; i += 2) {
            int odd_num = nums.at(i - 1);
            if (i + 1 != n) {
                // 奇数要比偶数最小的小
                odd_num = std::min(odd_num, nums.at(i + 1));
            }

            if (nums.at(i) >= odd_num) {
                res1 += (nums.at(i) - odd_num) + 1;
            }
        }

        // 处理A[0] < A[1] > A[2] < A[3] > A[4] < ...
        for (size_t i = 0; i < n; i += 2) {
            int even_num = INT_MAX;
            if (i) {
                even_num = nums.at(i - 1);
            }

            if (i + 1 != n) {
                // 偶数要比奇数数最小的小
                even_num = std::min(even_num, nums.at(i + 1));
            }

            if (nums.at(i) >= even_num) {
                res2 += (nums.at(i) - even_num) + 1;
            }
        }

        return std::min(res1, res2);
    }
};
// @lc code=end

/*
[9,6,1,6,2]\n
[1,3,1]\n
[1,2,3]\n
[1,1,1,1]\n
[1,1,1]\n
[1]\n
[1,2,2,1]\n
*/