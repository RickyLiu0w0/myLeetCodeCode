/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    /*
    string reverseWords(string s) {
        vector<string> dict;
        string sub_s;
        size_t i = 0, size = s.length();
        while (i < size) {
            if (s[i] == ' ') {
                if (sub_s.size()) {
                    dict.emplace_back(sub_s);
                    sub_s.clear();
                }
                while (i < (size - 1) && s[i + 1] == ' ') ++i;
            } else {
                sub_s.push_back(s[i]);
            }
            ++i;
        }

        if (sub_s.size()) {
            dict.emplace_back(sub_s);
            sub_s.clear();
        }

        for(auto iter = dict.rbegin(); iter < dict.rend(); iter++) {
            sub_s.append(*iter);
            sub_s.push_back(' ');
        }
        sub_s.pop_back();
        return sub_s;
    }
    */
    string reverseWords(string s) {
        // 双指针
        int j = s.length() - 1;
        int i = j;
        string res;

        while (i > -1) {
            while (j > -1 && ' ' == s[j]) {
                // 去除空格
                --j;
            }

            i = j;
            while (i > -1 && ' ' != s[i]) {
                // 寻找单词
                --i;
            }

            // [i, j]是单词
            if (i != j) {
                res.append(s.substr(i + 1, j - i));
                res.push_back(' ');
            } else {
                break;
            }

            j = --i;
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
