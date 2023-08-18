/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-10
 * 123/123 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 40.85 % of cpp submissions (5.8 MB)
*/
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int mul = 1;
        while(n) {
            int i= n % 10;
            n /= 10;
            sum += i;
            mul *= i; 
        }
        return mul - sum;
    }
};
// @lc code=end

