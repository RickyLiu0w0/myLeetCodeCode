/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 *
 * https://leetcode.cn/problems/prime-arrangements/description/
 *
 * algorithms
 * Easy (49.43%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 19.4K
 * Testcase Example:  '5'
 *
 * 请你帮忙给从 1 到
 * n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1
 * 开始）上；你需要返回可能的方案总数。
 *
 * 让我们一起来回顾一下「质数」：质数一定是大于 1
 * 的，并且不能用两个小于它的正整数的乘积来表示。
 *
 * 由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 5
 * 输出：12
 * 解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1]
 * 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。
 *
 *
 * 示例 2：
 *
 * 输入：n = 100
 * 输出：682289015
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 100
 *
 *
 */

#include "AllInclude.h"

// @lc code=start
#define MOD 1000000007

class Solution {
public:
    int numPrimeArrangements(int n) {
        // 统计n数中的素数个数np，以及非素数个数n-np
        // 结果就是A(np,np)xA(n-np, n-np)
        int primeCount = 0;
        uint8_t i = 2, j;
        for (; i <= n; ++i) {
            j = 2;
            for (; j < i; ++j) {
                if (!(i % j)) {
                    break;
                }
            }

            if (j == i) {
                ++primeCount;
            }
        }

        uint64_t res = 1, res2 = 1, k;
        for (k = 2; k <= primeCount; ++k) {
            res = (res % MOD) * k;
        }

        for (k = 2; k <= n - primeCount; ++k) {
            res = (res % MOD) * k;
        }

        // k = 0;
        // while (res2) {
        //     if (res2 & 0x1) {
        //         k = (k + res) % MOD;
        //     }

        //     res = (res * 2) % MOD;
        //     res2 >>= 1;
        // }

        return res % MOD;
    }
};
// @lc code=end

/*
5\n
10\n
20\n
40\n
50\n
100
*/
