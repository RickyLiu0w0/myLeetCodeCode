/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-11-17
 * 53/53 (100 ms)
 * Your runtime beats 97.73 % of cpp submissions
 * Your memory usage beats 87.22 % of cpp submissions (36 MB)
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        set<string> true_set;
        set<string> false_set;

        size_t sPtr, wPtr, s_size = s.length();
        int res = 0;
        for (auto& word : words) {
            if (true_set.end() != true_set.find(word)) {
                ++res;
                continue;
            }

            if (false_set.end() != false_set.find(word)) {
                continue;
            }

            wPtr = sPtr = 0;
            size_t word_size = word.length();
            while (wPtr < word_size) {
                sPtr = s.find_first_of(word.at(wPtr), sPtr);
                if (sPtr == string::npos) {
                    false_set.insert(word);
                    break;
                }
                ++sPtr;
                ++wPtr;
            }

            if (wPtr == word_size) {
                true_set.insert(word);
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
