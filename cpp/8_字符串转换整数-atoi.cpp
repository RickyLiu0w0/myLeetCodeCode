/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-10
 * 1084/1084 (8 ms)
 * Your runtime beats 27.29 % of cpp submissions
 * Your memory usage beats 77.74 % of cpp submissions (6.8 MB)
*/
class Solution {
public:
    int myAtoi(string s) {
        // 确实开头
        int n = s.length();
        int begin = 0;
        while (begin < n) {
            char c = s[begin++];
            if (begin < n && c == '0' && !isdigit(s[begin])) {
                return 0;
            }

            if (c == '+' || c == '-' || (isdigit(c) && c != '0')) {
                begin--;
                break;
            } else if (c != ' ' && c != '0') {
                return 0;
            }
        }

        if (n == begin) {
            return 0;
        }

        // 确认结尾
        int end = begin + 1;
        while (end < n) {
            char c = s[end];
            if (!isdigit(c)) {
                break;
            }

            ++end;
        }

        bool flag = true;
        if (s[begin] == '-') {
            flag = false;
            begin++;
        } else if (s[begin] == '+') {
            begin++;
        }

        while (s[begin] == '0') {
            begin++;
        }

        // 有效区间[begin, end)
        // cout << "[" << begin << ", " << end << ")\n";
        if (end - begin > to_string(INT_MAX).length()) {
            // 长度超出32正常范围
            if (!flag) {
                return INT_MIN;
            }
            return INT_MAX;
        }

        long long res = 0LL;

        for (int cur = begin; cur < end; ++cur) {
            res = res * 10 + (s[cur] - '0');
            if (res > INT_MAX && flag) {
                return INT_MAX;
            } else if (!flag && -res < INT_MIN) {
                return INT_MIN;
            }
        }

        if (!flag) {
            res = -res;
        }

        if (res > INT_MAX) {
            return INT_MAX;
        } else if (res < INT_MIN) {
            return INT_MIN;
        }

        return res;
    }
};
// @lc code=end
/*
"-2147483648"\n
"-91283472332"\n
"-000000000000001"\n
"00000-42a1234"\n
"42"\n
"   -42"\n
"4193 with words"\n
""\n
"000000000000000000000000000000000000000000000000"\n
"0000000000000000000000000000000000000000000000001"\n
"000000000000000000000100000000000000000000000000001"\n
"000000000000000000000-1000000000000000000000000000000000001"\n
"00000000000000000000010.0000000000000000000000000000000000000001"\n
*/