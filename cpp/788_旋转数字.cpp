/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-09-25
 * 50/50 (24 ms)
 * Your runtime beats 32.07 % of cpp submissions
 * Your memory usage beats 40.22 % of cpp submissions (5.9 MB)
*/
class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            if (rotatedDigit(i)) {
                ++res;
            }
        }
        return res;
    }

private:
    bool rotatedDigit(int n) {
        string numString = to_string(n);
        int size = numString.length();
        for (int i = 0; i < size; ++i) {
            switch (numString[i]) {
                case '0':
                case '1':
                case '8':
                    break;

                case '2':
                    numString[i] = '5';
                    break;

                case '5':
                    numString[i] = '2';
                    break;

                case '6':
                    numString[i] = '9';
                    break;

                case '9':
                    numString[i] = '6';
                    break;

                default:
                    return false;
            }
        }

        return n != stoi(numString);
    }
};
// @lc code=end
