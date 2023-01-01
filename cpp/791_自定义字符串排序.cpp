/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-11-13
 * 39/39 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 30.09 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    string customSortString(string order, string s) {
        array<uint8_t, 26> map = {0};

        for (auto &c : s) {
            map.at(c - 'a') += 1;
        }

        string res = "";
        for (auto &c : order) {
            res += string(map.at(c - 'a'), c);
            map.at(c - 'a') = 0;
        }

        for (size_t i = 0; i < 26; ++i) {
            if (map.at(i)) {
                res += string(map.at(i), i + 'a');
            }
        }
        return res;
    }
};
// @lc code=end
/*
"cbafg"\n"abcd"
*/