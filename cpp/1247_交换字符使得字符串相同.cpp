/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

#include "AllInclude.h"

/**
 * Accepted 2023-02-25
 * 70/70 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 91.14 % of cpp submissions (6 MB)
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1 == s2) {
            return 0;
        }

        if (s1.size() != s2.size()) {
            return -1;
        }
        const size_t s2_size = s2.size();
        // 先把相同项去掉
        for (size_t i1 = 0, i2 = 0; i2 < s2_size; ++i2, ++i1) {
            if (s1[i1] == s2[i2]) {
                s1.erase(i1, 1);
                --i1;
            }
        }

        const size_t s1_size = s1.size();

        // 如果长度是奇数，则直接失败
        if (s1_size & 0b1) {
            return -1;
        }

        /**
         * "xx"
         * "yy" -> 1，解决2个数只需要交换1次，则 res = (size / 2)
         *
         * "yx"
         * "xy" -> 2，先交换一次变成上面第一种情况，则 res = (size / 2) + 1
         *
         * 统计x和y同时是奇数还是偶数，因为总数是偶数，所以只能(奇+奇)或(偶+偶)
         */
        size_t count = 0;
        // 统计x就可以了
        for (auto c : s1) {
            if (c == 'x') {
                ++count;
            }
        }

        if (count & 0b1) {
            // 奇数
            return (s1_size >> 1) + 1;
        } else {
            // 偶数
            return s1_size >> 1;
        }
    }
};
// @lc code=end

/*
"xxyyxyxyxx"\n"xyyxyxxxyx"\n
"xx"\n"xy"\n
"xx"\n"yy"\n
"yx"\n"xy"\n
"xy"\n"xy"\n
"xxxxyyyy"\n"yyyyxyyx"\n
"yxyxxxyyxxyxxxx"\n"yyyxyyyxyxxxyxy"
*/