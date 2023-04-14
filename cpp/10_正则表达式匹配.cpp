/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-14
 * 354/354 (8 ms)
 * Your runtime beats 39.84 % of cpp submissions
 * Your memory usage beats 5.02 % of cpp submissions (16.9 MB)
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        return dp(s, 0, p, 0);
    }

private:
    unordered_map<string, bool> memo;  // 备忘录

    // s[..i]和p[..j]是否匹配
    bool dp(string& s, int i, string& p, int j) {
        // base case
        int m = s.length(), n = p.length();
        if (j == n) {
            // 模式指针已走到末尾，现在只需判断字符串指针i是否已到末尾
            return m == i;
        }

        if (m == i) {
            // 字符串指针i已到末尾
            // 剩下的模式可能有三种情况
            // A*B (false)
            // A*B* (true)
            // A*BB (false)
            if ((n - j) % 2) {
                // A*B
                return false;
            }
            for (; j < n; j += 2) {
                if (p[j + 1] != '*') {
                    // A*BB (false)
                    return false;
                }
            }

            return true;  // A*B* (true)
        }
        /*------------ base case end -------------------*/
        string key = to_string(i) + "," + to_string(j);
        bool res = false;
        if (memo.count(key) != 0) return memo[key];
        if (s[i] == p[j] || p[j] == '.') {
            // 匹配上了
            if (j < n - 1 && p[j + 1] == '*') {
                // 这是一个通配符，但是不确定有没有用上
                res =  /* 没用上 */ dp(s, i, p, j + 2) || /* 用上了，通过递归才直到用了多少次 */ dp(s, i + 1, p, j);
            } else {
                // 老老实实一个一个匹配
                res =  dp(s, i + 1, p, j + 1);
            }
        } else {
            // 匹配不上
            if (j < n - 1 && p[j + 1] == '*') {
                // 这是一个通配符（免死金牌），但0次匹配，j直接到下一个
                res = dp(s, i, p, j + 2);
            } else {
                // 没有免死金牌，无了
                res = false;
            }
        }
        memo[key] = res;
        return res;
    }
};
// @lc code=end
