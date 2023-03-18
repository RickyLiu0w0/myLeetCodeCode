/*
 * @lc app=leetcode.cn id=1616 lang=cpp
 *
 * [1616] 分割两个字符串得到回文串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-18
 * 109/109 (64 ms)
 * Your runtime beats 17.86 % of cpp submissions
 * Your memory usage beats 5.35 % of cpp submissions (44 MB)
 */
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a) || check(a, a) || check(b, b);
    }

private:
    bool check(string a, string b) {
        int len = a.length();
        int end = len / 2;

        for (int i = 0; i < end; ++i) {
            if (a[i] != b[len - i - 1]) {
                string sub = b.substr(i, len - 2 * i);
                string sub2 = a.substr(i, len - 2 * i);
                return i? (check(sub, sub) || check(sub2, sub2)) : false;
            }
        }
        return true;
    }
};
// @lc code=end

/*
"xxx"\n"yyy"\n
"pvhmupgqeltozftlmfjjde"\n"yjgpzbezspnnpszebzmhvp"\n
"aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd"\n"uvebspqckawkhbrtlqwblfwzfptanhiglaabjea"\n
*/
