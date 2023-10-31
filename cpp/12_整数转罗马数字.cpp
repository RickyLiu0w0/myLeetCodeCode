/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-09
 * 3999/3999 (4 ms)
 * Your runtime beats 83.54 % of cpp submissions
 * Your memory usage beats 32.85 % of cpp submissions (6 MB)
 */
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        // 处理1000位
        int cnt = num / 1000;
        num %= 1000;
        while (cnt--) {
            res += "M";
        }

        // 处理500、100位，注意900和400
        cnt = num / 100;
        num %= 100;
        if (cnt == 9) {
            res += "CM";
        } else if (cnt == 4) {
            res += "CD";
        } else {
            if (cnt >= 5) {
                cnt -= 5;
                res += "D";
            }
            while (cnt--) {
                res += "C";
            }
        }

        // 处理50、10位，注意90和40
        cnt = num / 10;
        num %= 10;
        if (cnt == 9) {
            res += "XC";
        } else if (cnt == 4) {
            res += "XL";
        } else {
            if (cnt >= 5) {
                cnt -= 5;
                res += "L";
            }
            while (cnt--) {
                res += "X";
            }
        }

        // 处理5、1位注意9和4
        cnt = num;
        if (cnt == 9) {
            res += "IX";
        } else if (cnt == 4) {
            res += "IV";
        } else {
            if (cnt >= 5) {
                cnt -= 5;
                res += "V";
            }
            while (cnt--) {
                res += "I";
            }
        }

        return res;
    }
};
// @lc code=end

/*
3\n
4\n
9\n
58\n
1994\n
3999
*/