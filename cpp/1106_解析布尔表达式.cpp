/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-11-05
 * 75/75 (8 ms)
 * Your runtime beats 58.10 % of cpp submissions
 * Your memory usage beats 98.00 % of cpp submissions (6.7 MB)
 */

class Solution {
public:
    bool parseBoolExpr(string expression) { return help(expression, 0, expression.length()); }

private:
    bool help(string& str, size_t begin, size_t end) {
        size_t i = begin + 2;
        size_t j = i + 1;
        uint16_t stack = 0;
        switch (str[begin]) {
            case 'f':
                return false;
                break;

            case 't':
                return true;
                break;

            case '!':
                return !help(str, i, end - 1);
                break;

            case '&':
                while (j < end) {
                    if (str[j] == '(') {
                        ++stack;
                    }

                    if (str[j] == ')') {
                        --stack;
                    }

                    if (str[j] == ',' && stack == 0) {
                        // 遇到一个表达式
                        // 短路运算
                        if (!help(str, i, j)) {
                            return false;
                        }
                        i = j + 1;
                    }
                    ++j;
                }
                return help(str, i, j - 1);
                break;

            default:  // |
                while (j < end) {
                    if (str[j] == '(') {
                        ++stack;
                    }

                    if (str[j] == ')') {
                        --stack;
                    }

                    if (str[j] == ',' && stack == 0) {
                        // 遇到一个表达式
                        // cout << "i: " << i << " j: " << j << "\n";
                        // 短路运算
                        if (help(str, i, j)) {
                            return true;
                        }
                        i = j + 1;
                    }
                    ++j;
                }
                // cout << "i: " << i << " j: " << j << "\n";
                return help(str, i, j - 1);
                break;
        }
    }
};
// @lc code=end
/*
""!(f)"\n
"|(f,t)"\n
"&(t,f)"\n
"|(&(t,f,t),!(t))"\n
"|(&(|(f)),|(f,f,f,t),&(t,f,t),!(t))"\n
"!(&(&(!(&(f)),&(t),|(f,f,t)),&(t),&(t,t,f)))""
*/