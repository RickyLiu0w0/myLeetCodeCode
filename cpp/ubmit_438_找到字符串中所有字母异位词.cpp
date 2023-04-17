/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> res;
        if (n < p.length()) {
            return {};
        }
        unordered_map<char, int> window;
        for (auto& c : p) {
            window[c]++;
        }

        int l = 0, r = 0, m = window.size();

        while (r < n) {
            char c = s[r++];

            // 对窗口的一系列更新
            if (window.count(c)) {
                window[c]--;
                if (0 == window[c]) {
                    m--;
                }
            }

            // 判断缩小左窗口的条件
            while (r - l == p.length()) {
                
                if (m == 0) {
                    // 一个符合条件的窗口
                    res.emplace_back(l);
                }

                char cc = s[l++];
                if (window.count(cc)) {
                    window[cc]++;
                    if (1 == window[cc]) {
                        m++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

