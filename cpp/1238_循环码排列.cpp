/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

#include "AllInclude.h"

/**
 * Accepted 2023-02-23
 * 47/47 (12 ms)
 * Your runtime beats 83.72 % of cpp submissions
 * Your memory usage beats 57.36 % of cpp submissions (17.3 MB)
*/

// @lc code=start
class Solution {
public:
    // 这题关键是格雷码，当作普通的二进制转换回来即为答案
    vector<int> circularPermutation(int n, int start) {
        size_t size = std::pow(2, n);
        vector<int> res;

        // start转为gray，计算start是从哪个格雷码开始
        start ^= (start >> 16);
        start ^= (start >> 8);
        start ^= (start >> 4);
        start ^= (start >> 2);
        start ^= (start >> 1);

        int count = 0;
        for (; count < size; ++start) {
            if (start == size) {
                start = 0;
            }

            // 格雷码转化为普通数
            res.emplace_back(start ^ (start >> 1));
            ++count;
        }

        return res;
    }
};
// @lc code=end

/*
16\n25768\n
2\n3\n
3\n2
*/