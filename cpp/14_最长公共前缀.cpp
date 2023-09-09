/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-09
 * 124/124 (4 ms)
 * Your runtime beats 75.43 % of cpp submissions
 * Your memory usage beats 45.88 % of cpp submissions (9 MB)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].length() || strs.front()[i] != strs[j][i]) {
                    return strs.front().substr(0, i);
                }
            }
        }
        return strs.front();
    }
};
// @lc code=end

/*
["flower","flow","flight"]\n
["dog","racecar","car"]
*/