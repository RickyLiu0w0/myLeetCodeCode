/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-11
 * 25/25 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 26.36 % of cpp submissions (6.7 MB)
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const string alpha[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string path = "";
        function<void(int)> backTrack = [&](int i) {
            if (i == digits.size()) {
                res.emplace_back(path);
                return;
            }

            int index = digits[i] - '2';
            for (auto c : alpha[index]) {
                path.push_back(c);
                backTrack(i + 1);
                path.pop_back();
            }
        };
        if (digits.size() == 0) {
            return {};
        }
        backTrack(0);
        return res;
    }
};
// @lc code=end

/*
"23"\n
""\n
"9"
*/