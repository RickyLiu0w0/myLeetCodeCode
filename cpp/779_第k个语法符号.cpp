/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-20
 * 55/55  (4 ms)
 * Your runtime beats 13.43 % of cpp submissions
 * Your memory usage beats 5.65 % of cpp submissions (6.1 MB)
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        bool flag = true;
        while (k > 2) {
            flag = !flag;
            int temp = k - pow(2, int(log(k) / log(2))); 
            k = temp ? temp : k / 2;
        }
        return k == 2 ? flag : !flag;
    }
};
// @lc code=end
/*
30\n
1\n
30\n
2\n
30\n
3\n
30\n
4\n
30\n
5\n
30\n
6\n
30\n
7\n
30\n
8\n
30\n
9\n
30\n
10\n
30\n
11\n
30\n
12\n
30\n
13\n
30\n
14\n
30\n
15\n
30\n
16\n
*/
