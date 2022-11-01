/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-30
 * 63/63 (4 ms)
 * Your runtime beats 89.62 % of cpp submissions
 * Your memory usage beats 97.89 % of cpp submissions (9.1 MB)
 */
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res = {""};
        size_t res_size = 1;
        for (auto c : s) {
            if (c > 64  && c < 91) {
                // 大写字母
                for (size_t i = 0; i < res_size; ++i) {
                    res.emplace_back(res[i] + c);
                }
                c += 32;
                for (size_t i = 0; i < res_size; ++i) {
                    res[i] += c;
                }
                res_size *= 2;
            } else if (c > 96 && c < 123) {
                // 小写字母
                for (size_t i = 0; i < res_size; ++i) {
                    res.emplace_back(res[i] + c);
                }
                c -= 32;
                for (size_t i = 0; i < res_size; ++i) {
                    res[i] += c;
                }
                res_size *= 2;
            } else {
                for (size_t i = 0; i < res_size; ++i) {
                    res[i] += c;
                }      
            }
        }
        return res;
    }
};
// @lc code=end

