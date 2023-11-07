/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-25
 * 216/216 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 29.57 % of cpp submissions (6.3 MB)
 */
int PRE_NUM[1001];

auto pre = []() -> int {
    for (int num = 1; num < 1001; ++num) {
        string s = to_string(num * num);
        int n = s.length();
        function<bool(int, int)> dfs = [&](int pos, int sum) -> bool {
            if (pos == n) {
                return num == sum;
            }
            int x = 0;
            // 选择
            for (int j = pos; j < n; ++j) {
                x = x * 10 + s[j] - '0';
                if(dfs(j + 1, sum + x)) {
                    return true;
                }
            }
            return false;
        };
        PRE_NUM[num] = PRE_NUM[num - 1] + (dfs(0, 0) ? num * num: 0);
    }
    return 0;
}();

class Solution {
public:
    int punishmentNumber(int n) {
        return PRE_NUM[n];
    }
};
// @lc code=end
