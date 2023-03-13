/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

#include "AllInclude.h"

// @lc code=start
const int MOD = 1337;
class Solution {
    /**
     * a^(1234) == a^4 * [a^(123)]^10
     */
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }

        int t = b.back();
        b.pop_back();

        int one = my_pow(a, t);
        int two = my_pow(superPow(a, b), 10);
        return (one * two) % MOD;
    }

private:
    /*
        int my_pow(int a, int k) {
            int res = 1;
            a %= MOD;

            for (int _ = 0; _ < k; ++_) {
                res *= a;
                res %= MOD;
            }

            return res;
        }
    */
    int my_pow(int a, int k) {
        /**
         *           ________________________
         *          | a ^ (b - 1) * a; b为奇数
         * a ^ b = <
         *          | [a ^ (b / 2)] ^ 2; b为偶数
         *           ________________________
         */
        if (k == 0) {
            return 1;
        }

        a %= MOD;

        if (k & 1) {
            // 奇数
            return (my_pow(a, k - 1) * a) % MOD;
        } else {
            // 偶数
            int res = my_pow(a, k / 2);
            return (res * res) % MOD;
        }
    }
};
// @lc code=end
