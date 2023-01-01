/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-31
 * 64/64 (8 ms)
 * Your runtime beats 70.04 % of cpp submissions
 * Your memory usage beats 68.59 % of cpp submissions (7.4 MB)
*/
class Solution {
public:
    int magicalString(int n) {
        if (n < 4)
            return 1;

        bool one = true;
        string s = "122";
        size_t oneCount = 1, numCounet = 3, index = 2;
        while (1) {
            numCounet += s[index] - '0';
            if (0 == index % 2) {
                oneCount += s[index] - '0';
            }

            if (numCounet >= n) {
                // 可以返回结果了
                if (0 == index % 2 && numCounet != n) {
                    // 加多了一位
                    return oneCount - 1;
                } else {
                    // 这个位置是2，不影响原结果
                    cout << s << endl;
                    return oneCount;
                }
            }

            // 构造S字符串
            if (one) {
                // 该加1了
                s.append(string(s[index] - '0', '1'));
                one = false;
            } else {
                // 该加2了
                s.append(string(s[index] - '0', '2'));
                one = true;
            }
            ++index;
        }
        return -1;
    }
};
// @lc code=end
/*
1\n
2\n
3\n
4\n
5\n
6\n
7\n
8\n
9\n
*/
