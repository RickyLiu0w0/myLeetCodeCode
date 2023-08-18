/*
 * @lc app=leetcode.cn id=2423 lang=cpp
 *
 * [2423] 删除字符使频率相同
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-29
 * 49/49 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 7.91 % of cpp submissions (6.2 MB)
*/
class Solution {
public:
    bool equalFrequency(string word) {
        array<int, 27> hash_map; // 27是防止全部字母都出现了
        hash_map.fill(0);

        for (auto& w : word) {
            hash_map[w - 'a']++;
        }

        int n = word.length();

        for (int i = 0; i < n; ++i) {
            hash_map[word[i] - 'a']--;

            set<int> s(hash_map.begin(), hash_map.end());

            if (s.size() == 2) {
                return true;
            }

            hash_map[word[i] - 'a']++;
        }
        return false;
    }
};
// @lc code=end
/*
"abcdefghijklmnopqrstuvwxyznabcdefghijklmnopqrstuvwxyz"\n
*/