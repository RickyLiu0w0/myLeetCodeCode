/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-07-03 13:25
 * 39/39 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 58 % of cpp submissions (5.8 MB)
 */
class Solution {
public:
    int nextGreaterElement(int n) {
        string nString = to_string(n);
        uint8_t nStringSize = nString.length();
        uint8_t i = nStringSize - 1;  // 个位
        if (n < 10)
            return -1;

        while (i > 0) {
            if (nString[i] <= nString[i - 1]) {
                --i;
            } else {
                break;
            }
        }

        if (!i) return -1;

        char charTemp = nString[i];
        uint8_t index = i--;

        for (uint8_t j = i + 2; j < nStringSize; ++j) {
            if (nString[i] < nString[j] && nString[j] < charTemp) {
                charTemp = nString[j];
                index = j;
            }
        }

        nString.erase(index, 1);
        nString.insert(i++, 1, charTemp);

        sort(nString.begin() + i, nString.end(), [](char& a, char& b) -> bool {
                return a < b;
            });

        long res = atol(nString.c_str());

        if (res > INT_MAX)
            return -1;
        else
            return (int)res;
    }
};
// @lc code=end

/*
12\n
21\n
51342\n
222\n
1122\n
2122\n
53721\n
2147483476\n
5145326
*/