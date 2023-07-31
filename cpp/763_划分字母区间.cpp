/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-30
 * 118/118 (8 ms)
 * Your runtime beats 18.84 % of cpp submissions
 * Your memory usage beats 24.41 % of cpp submissions (6.6 MB)
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> begin_v(26, -1);
        vector<int> end_v(26);
        size_t n = s.length();
        for (size_t i = 0; i < n; ++i) {
            size_t c = s[i] - 'a';
            if (begin_v[c] == -1) {
                // 记录第一次出现位置
                begin_v[c] = i;
            }

            end_v[c] = i; // 记录下结束位置
        }

        vector<pair<int, int>> v;
        for (size_t i = 0; i < 26; ++i) {
            if (begin_v[i] != -1) {
                // 出现在s中
                v.emplace_back(begin_v[i], end_v[i]);
            }
        }

        sort(v.begin(), v.end());

        int begin = v.front().first;
        int end = v.front().second;

        n = v.size();
        vector<int> res;
        for (int i = 1; i < n; ++i) {
            if (v[i].first < end) {
                end = max(end, v[i].second);
            } else {
                res.emplace_back(end - begin + 1);
                begin = v[i].first;
                end = v[i].second;
            }
        }
        res.emplace_back(end - begin + 1);
        return res;
    }
};
// @lc code=end

/*
"aaabbbcccdddbee"\n
"eccbbbbdec"\n
"ababcbacadefegdehijhklij"\n
*/