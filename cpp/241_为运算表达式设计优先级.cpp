/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

#include "AllInclude.h"
/**
 * Accepted 2022-07-01 00:05
 * 25/25 (4 ms)
 * Your runtime beats 67.87 % of cpp submissions
 * Your memory usage beats 17.94 % of cpp submissions (11.3 MB)
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // 递归思路
        // (2*3)-(4*5)
        // 该函数分别计算左和右的结果，然后遍历左边所有结果和右边左右结果的组合，作出运算操作
        uint8_t expSize = expression.length(), i;
        vector<int> res;

        for (i = 0; i < expSize - 1; ++i) {
            char cha = expression[i];
            if ('+' == cha || '-' == cha || '*' == cha) {
                vector<int> right = this->diffWaysToCompute(expression.substr(0, i));
                vector<int> left = this->diffWaysToCompute(expression.substr(i + 1, expSize - i - 1));

                for (int x : right) {
                    for (int y : left) {
                        switch (cha) {
                            case '+':
                                res.push_back(x + y);
                                break;

                            case '-':
                                res.push_back(x - y);
                                break;

                            case '*':
                                res.push_back(x * y);
                                break;

                            default:
                                break;
                        }
                    }
                }
            }
        }

        if (res.empty()) {
            res.push_back(atoi(expression.c_str()));
        }

        return res;
    }
};
// @lc code=end
/*
""2"\n
"2+2+2"\n
"2*3-4*5"""
*/