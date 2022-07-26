/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    string fractionAddition(string expression) {
        // expression += "0/1"; // 保证没有负号
        uint16_t stringSize = expression.length();
        string left, right;
        int numeratorLeft, numeratorRight, denominatorLeft, denominatorRight;
        for (uint16_t index = 1; index < stringSize - 1; ++index) {
            if ('+' != expression[index] && expression[index] != '-') {
                continue;
            }

            left = fractionAddition(expression.substr(0, index));
            right = fractionAddition(expression.substr(index + 1, stringSize - index - 1));

            for (uint8_t j = 1; j < left.length() - 1; ++j) {
                if (left[j] == '/') {
                    numeratorLeft = stoi(left.substr(0, j));  // 取得分子
                    denominatorLeft = stoi(left.substr(j + 1, left.length() - j - 1)); // 取得分母
                }
            }

            for (uint8_t j = 1; j < right.length() - 1; ++j) {
                if (left[j] == '/') {
                    numeratorRight = stoi(right.substr(0, j));  // 取得分子
                    numeratorRight = stoi(right.substr(j + 1, right.length() - j - 1)); // 取得分母
                }
            }

            // left == "a/b"
            // right == "c/d"
            switch (expression[index]) {
                case '+':
                    /* code */
                    break;

                case '-':
                    /* code */
                    break;

                default:
                    break;
            }
        }
        return "";
    }
};
// @lc code=end
