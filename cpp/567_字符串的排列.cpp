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
        unordered_map<char, int> map_;
        int target_size = s1.size();
        int n = s2.length();
        if (n < target_size) {
            return false;
        }

        for (auto& c : s1) {
            map_[c]++;
        }

        int l = 0, r = 0;
        while (r < n) {
            // 右窗口扩大
            while (r < n && !map_.count(s2[r])) {
                r++;
                l++;
            }

            while (r < n && map_.count(s2[r]) && map_[s2[r]]) {
                map_[s2[r]]--;
                target_size--;
                ++r;
            }

            if (!target_size) {
                return true;
            }

            // 左窗口缩小
            while (l < r) {
                if (map_.count(s2[l])) {
                    map_[s2[l]]++;
                    target_size++;
                }
                ++l;
                if (map_.count(s2[r])) {
                    break;
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