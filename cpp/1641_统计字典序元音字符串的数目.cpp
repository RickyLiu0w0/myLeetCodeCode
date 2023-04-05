/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-29
 * 41/41 (368 ms)
 * Your runtime beats 5.11 % of cpp submissions
 * Your memory usage beats 58.72 % of cpp submissions (5.8 MB)
 */
class Solution {
public:
    int countVowelStrings(int n) {
        int res = 0;
        int f[n][5];
        memset(f, 0, sizeof f);
        function<int(int, int)> backtrack  = [&](int size, int begin) -> int{
            if (n <= size) {
                return 1;
            }

            if (f[size][begin]) {
                return f[size][begin];
            }

            int r = 0;
            // 选择列表
            for (int i = begin; i < 5; ++i) {
                r += backtrack(size + 1, i); // 可以将自己加入
            }
            f[size][begin] = r;
            return r;
        };
        return backtrack(0, 0);
    }
};
// @lc code=end

