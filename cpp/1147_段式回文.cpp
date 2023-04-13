/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-12
 * 84/84 (8 ms)
 * Your runtime beats 34.27 % of cpp submissions
 * Your memory usage beats 47.19 % of cpp submissions (8.1 MB)
 */
class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.length();
        int left_first = 0, left_end = 1;
        int right_end = n, right_first = n - 1;
        int res = 1;
        while (left_end <= right_first) {
            if (text.substr(left_first, left_end - left_first) == text.substr(right_first, right_end - right_first)) {
                if (left_end == right_first) {
                    res++;
                } else {
                    res += 2;
                }
                left_first = left_end;
                right_end = right_first;
            }
            left_end++;
            right_first--;
        }
        return res;
    }
};
// @lc code=end
/*
"merchant"\n
"a"\n
"ab"\n
"aa"\n
"antaprezatepzapreanta"\n
"ghiabcdefhelloadamhelloabcdefghi"\n
*/