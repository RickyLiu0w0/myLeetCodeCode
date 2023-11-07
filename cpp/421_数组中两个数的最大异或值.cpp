/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-04
 * 45/45 (1776 ms)
 * Your runtime beats 5.7 % of cpp submissions
 * Your memory usage beats 5.23 % of cpp submissions (482.8 MB)
 */
static const int SIZE = 2e5 * 31;
class Solution {
public:
    Solution() {
        for (int i = 0; i <= idx; i++) tr[i][0] = tr[i][1] = 0;
        idx = 0;
    }

    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        for (auto x : nums) {
            add(x);
            int y = get_val(x);
            res = max(res, x ^ y);
        }
        return res;
    }

private:
    static vector<vector<int>> tr;
    static int idx;

    void add(int x) {
        int p = 0;
        for (int i = 31; i > -1; --i) {
            int u = (x >> i) & 1;
            if (tr[p][u] == 0) {
                tr[p][u] = ++idx;
            }
            p = tr[p][u];
        }
    }

    // 返回和x最大异或的数
    int get_val(int x) {
        int p = 0, res = 0;
        for (int i = 31; i > -1; --i) {
            int u = (x >> i) & 1;
            int o_u = 1 - u;  // u的相反
            if (tr[p][o_u]) {
                // 找到相反的数
                res |= (o_u << i);
                p = tr[p][o_u];
            } else {
                // 找不到相反的数
                res |= (u << i);
                p = tr[p][u];
            }
        }
        return res;
    }
};
vector<vector<int>> Solution::tr = vector<vector<int>>(SIZE, vector<int>(2, 0));
int Solution::idx = 0;
// @lc code=end

/*
[14,70,53,83,49,91,36,80,92,51,66,70]\n
[3,10,5,25,2,8]\n
[0]\n
*/