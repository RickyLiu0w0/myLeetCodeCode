/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) { 
        sort(words.begin(), words.end(), [](string& x, string& y)->bool{
            return x.length() < y.length(); // 按长度排
        });

        int n = words.size();

        // 用32位存储26个字母的存在情况
        vector<uint32_t> bitmap(n, 0);

        for (int i = 0; i < n; ++i) {
            for (auto&c : words.at(i)) {
                bitmap.at(i) |= (1 << (c - 'a'));
            }
        }

        // 从后暴力遍历
        unsigned long res = 0;
        for (int i = n - 1; i > -1; --i) {
            for (int j = i - 1; j > -1; --j) {
                if ((bitmap[i] & bitmap[j]) == 0) {
                    // 这两个无重叠
                    res = max(res, words[i].length() * words[j].length());
                }
            }
        }
        return res;
    }
};
// @lc code=end

