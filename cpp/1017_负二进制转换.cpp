/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-05
 * 170/170 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 7.62 % of cpp submissions (6 MB)
*/
class Solution {
public:
    string baseNeg2(int n) {
        if (!n) return "0";
        auto f = [](int n, int K) -> vector<int> {
            vector<int> res;
            while (n) {
                int r = (n % K + abs(K)) % abs(K);
                n -= r;
                n /= K;
                res.emplace_back(r);
            }
            reverse(res.begin(), res.end());
            return res;
        };
        vector<int> res = f(n, -2);
        string s;
        for (auto x : res) {
            s.push_back(x + '0');
        }
        return s;
    }
};
// @lc code=end

