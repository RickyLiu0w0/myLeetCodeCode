/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-27
 * 63/63 (28 ms)
 * Your runtime beats 25 % of cpp submissions
 * Your memory usage beats 45.97 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    int countSubstrings(string s, string t) {
        // 暴力解法尝试
        // 用i代表s字符串的结尾位置，j表示t字符串的结尾位置，k表示s字符开始位置
        auto check = [](string& a, size_t a_begin, size_t a_end, string& b, size_t b_begin, size_t b_end) -> bool {
            if (b_end - b_begin != a_end - a_begin) {
                return false;
            }

            bool flag = true;
            for (size_t i = a_begin, j = b_begin; i < a_end; ++i, ++j) {
                if (a[i] != b[j]) {
                    if (flag) {
                        flag = false;
                    } else {
                        return false;
                    }
                }
            }
            return !flag;
        };

        int m = s.length(), n = t.length();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= i; ++k) {
                    int t_beg = j + k - i;
                    if (t_beg < 0) {
                        continue;
                    }
                    // if (check(s, k, i + 1, t, t_beg, j + 1)) {
                    //     cout << "(" << k << ", " << i << ")||(" << t_beg << ", " << j << ")\n";
                    // }
                    res += check(s, k, i + 1, t, t_beg, j + 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end
