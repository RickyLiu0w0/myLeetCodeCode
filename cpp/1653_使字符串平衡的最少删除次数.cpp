/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-06
 * 157/157 (60 ms)
 * Your runtime beats 93.14 % of cpp submissions
 * Your memory usage beats 83.33 % of cpp submissions (21.5 MB)
*/
class Solution {
public:
    int minimumDeletions(string s) {
        int counter = s.length(); // a的数量
        for (auto& c : s) {
            // 'a' -> 0 'b' -> -1
            counter -= (c - 'a');
        }

        int res = counter;

        for (auto& c : s) {
            // 'a' -> -1 'b' -> 1
            counter += (c - 'a') * 2 - 1;
            res = std::min(res, counter);
        }

        return res;
    }
};
// @lc code=end

/*
""bbbbbbbaabb""
*/