/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-15
 * 49/49 (4 ms)
 * Your runtime beats 42.9 % of cpp submissions
 * Your memory usage beats 6.53 % of cpp submissions (7.7 MB)
*/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        uint8_t size = target.size();
        uint8_t index = 0;
        for(uint8_t i = 1; index < size; ++i) {
            if (target[index] == i) {
                res.emplace_back("Push");
                ++index;
            } else {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
        }
        return res;
    }
};
// @lc code=end

