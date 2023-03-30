/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int size_a = a.length(), size_b = b.size();
        int p_a = size_a - 1, p_b = size_b - 1;

        string res = "";
        bool carry = false;
        while (p_b > -1 && p_a > -1) {
            int temp = a[p_a] - '0' + b[p_b] - '0' + carry;
            if (temp > 1) {
                res.push_back('0' + temp - 2);
                carry = true;
            } else {
                res.push_back('0' + temp);
                carry = false;
            }
            --p_a;
            --p_b;
        }

        if (p_a == -1) {
            while (p_b > -1) {
                int temp = b[p_b] - '0' + carry;
                if (temp > 1) {
                    res.push_back('0' + temp - 2);
                    carry = true;
                } else {
                    res.push_back('0' + temp);
                    carry = false;
                }
                --p_b;
            }
        }

        if (p_b == -1) {
            while (p_a > -1) {
                int temp = a[p_a] - '0' + carry;
                if (temp > 1) {
                    res.push_back('0' + temp - 2);
                    carry = true;
                } else {
                    res.push_back('0' + temp);
                    carry = false;
                }
                --p_a;
            }
        }

        if (carry) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
