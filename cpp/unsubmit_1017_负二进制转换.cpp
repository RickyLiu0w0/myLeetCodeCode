/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    string baseNeg2(int n) {
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

