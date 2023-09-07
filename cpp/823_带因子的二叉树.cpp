/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-29
 * 
 * 48/48 (36 ms)
 * Your runtime beats 91.57 % of cpp submissions
 * Your memory usage beats 49.44 % of cpp submissions (9 MB)
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        // 动态规划，dp[i]表示i的根节点有多少符合题意得子树，由于自身是一个，所以初始化为1
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<long long> dp(n, 1);

        sort(arr.begin(), arr.end());

        unordered_map<int, int> m; // <值, 下标>
        for (int i = 0; i < n; ++i) {
            m[arr[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            for (int j = 0; j < i; ++j) {
                // arr[j] 比 arr[i] 小，所以有可能是arr[i]的因子
                int x = arr[j];
                if (val % x == 0 && m.count(val / x)) {
                    // 能被整除以及存在另一个因子
                    dp[i] += dp[m[x]] * dp[m[val / x]];
                }
            }
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
    }
};
// @lc code=end

/*
[2, 4]\n
[2, 4, 5, 10]
*/