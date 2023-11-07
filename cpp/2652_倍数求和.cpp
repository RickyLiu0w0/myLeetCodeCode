/*
 * @lc app=leetcode.cn id=2652 lang=cpp
 *
 * [2652] 倍数求和
 */

// @lc code=start
/**
 * Accepted 2023-10-17
 * 1000/1000 (4 ms)
 * Your runtime beats 52.17 % of cpp submissions
 * Your memory usage beats 7.03 % of cpp submissions (6.4 MB) 
 */
class Solution {
public:
    int sumOfMultiples(int n) {
        int res = 0;
        do {
            if (n % 3 == 0|| 0 ==  n % 7 || 0 == n % 5) {
                res += n;
            }
        } while (n--);
        return res;
    }
};
// @lc code=end

