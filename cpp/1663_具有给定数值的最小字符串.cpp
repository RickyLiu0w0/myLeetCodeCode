/*
 * @lc app=leetcode.cn id=1663 lang=cpp
 *
 * [1663] 具有给定数值的最小字符串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-01-26
 * 94/94 (68 ms)
 * Your runtime beats 9.22 % of cpp submissions
 * Your memory usage beats 5.68 % of cpp submissions (43.6 MB)
 **/
class Solution {
    /**
     * 9   9   9
     * 1   9   17
     * 1   1   25
     *
     * 14 14 14 14 17
     * 1  14 14 17 27
     * 1  1  17 27 27
     * 
     * 2\n31
     * 
     * 15 15 
     * 
     * 我们先将字符串的每个字符都初始化为 'a'，此时剩余的数值为 d = k - n
     */
public:
    string getSmallestString(int n, int k) {
        size_t right = n - 1;
        string array(n, 'a');
        int add_num = k - n;

        while(1) {
            if (add_num > 25) {
                array[right--] = 'z';
                add_num -= 25;
            } else {
                array[right] = 'a' + add_num;
                break;
            }
        }

        return array;
    }
};
// @lc code=end

/*
3\n27\n
5\n73\n
2\n31\n
1\n25\n
5\n31\n
100000\n2300000\n
21312\n76562
*/