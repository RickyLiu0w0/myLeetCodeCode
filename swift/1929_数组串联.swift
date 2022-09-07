/*
 * @lc app=leetcode.cn id=1929 lang=swift
 *
 * [1929] 数组串联
 */

// @lc code=start
/*
 Accepted 2022-09-04
 91/91 (48 ms)
Your runtime beats 93.75 % of swift submissions
 Your memory usage beats 6.25 % of swift submissions (14.5 MB)
*/
class Solution {
    func getConcatenation(_ nums: [Int]) -> [Int] {
        var res: [Int] = nums + nums;
        return res;
    }
}
// @lc code=end

