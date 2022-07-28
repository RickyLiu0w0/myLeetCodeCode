/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted
 * 105/105 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 53.59 % of cpp submissions (5.9 MB)
 */

class Solution {
public:
    string fractionAddition(string expression) {
        uint16_t stringSize = expression.length(), index;
        string left = "", right = "";
        int numeratorLeft, numeratorRight, denominatorLeft, denominatorRight,
            LCM, HCF;
        for (index = 1; index < stringSize - 1; ++index) {
            if ('+' == expression[index] || expression[index] == '-') {
                break;
            }
        }

        if (index == stringSize - 1) {
            return expression;
        }

        left = expression.substr(0, index);
        right = fractionAddition(expression.substr(index, stringSize - index));

        for (uint8_t j = 1; j < left.length() - 1; ++j) {
            if (left[j] == '/') {
                numeratorLeft = stoi(left.substr(0, j));  // 取得分子
                denominatorLeft = stoi(
                    left.substr(j + 1, left.length() - j - 1));  // 取得分母
            }
        }

        for (uint8_t j = 1; j < right.length() - 1; ++j) {
            if (right[j] == '/') {
                numeratorRight = stoi(right.substr(0, j));  // 取得分子
                denominatorRight = stoi(
                    right.substr(j + 1, right.length() - j - 1));  // 取得分母
            }
        }

        if (denominatorLeft != denominatorRight) {
            // 通分
            LCM = denominatorLeft * denominatorRight /
                  gcd(denominatorLeft, denominatorRight);
            numeratorLeft = LCM / denominatorLeft * numeratorLeft;
            numeratorRight = LCM / denominatorRight * numeratorRight;
            denominatorLeft = LCM;
        }

        // left == "a/b"
        // right == "c/d"
        // 用left的分子分母存储结果
        numeratorLeft = numeratorLeft + numeratorRight;

        // 约分，numeratorLeft/denominatorLeft
        // printf("left: %d, right: %d\n", numeratorLeft, denominatorLeft);
        if (numeratorLeft) {
            HCF = gcd(numeratorLeft, denominatorLeft);
        } else {
            HCF = denominatorLeft;
        }
        numeratorLeft /= HCF;
        denominatorLeft /= HCF;

        return to_string(numeratorLeft) + "/" + to_string(denominatorLeft);
    }

private:
    inline int gcd(int x, int y) {
        x = x > 0 ? x : -x;
        while (x != y) {
            if (x > y)
                x = x - y;
            else
                y = y - x;
        }
        return x;
    }
};
// @lc code=end
/*
"1/3-1/2"\n
"-1/2+1/2"\n
"-1/2+1/2+1/3"\n
"-2/4+10/3+4/4+6/8-1/10+9/7-7/9-8/7+9/2-10/1"
*/