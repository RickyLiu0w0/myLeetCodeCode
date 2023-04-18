/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        unordered_map<char, int> window;
        for (auto& c : s1) {
            window[c]++;
        }
        int m = window.size();
        int l = 0, r = 0, n = s2.length();

        while (r < n) {
            char c = s2[r++];

            // 进行窗口内数据更新
            if (window.count(c)) {
                window[c]--;
                if (window[c] == 0) {
                    m--;
                }
            }

            // 判断左窗口收缩条件
            while (r - l >= s1.length()) {
                // 找到符合题意的子串，成立
                if (m == 0) {
                    return true;
                }

                char cc = s2[l++];
                if (window.count(cc)) {
                    window[cc]++;
                    if (window[cc] == 1) {
                        m++;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
/*
"rokx"\n"otrxvfszxroxrzdsltg"\n
"zoologicoarchaeologist"\n"zoopsychologist"\n
"ab"\n"eidbaooo"\n
"adc"\n"dcda"\n
"ab"\n"eidboaoo"\n
*/