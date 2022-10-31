/*
 * @lc app=leetcode.cn id=1822 lang=swift
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
/*
    Accepted 2022-10-27
    76/76 cases passed (28 ms)
    Your runtime beats 41.67 % of swift submissions
    Your memory usage beats 91.67 % of swift submissions (13.7 MB)
*/
class Solution {
    func arraySign(_ nums: [Int]) -> Int {
        var bin: Bool = false;
        for num in nums {
            if num < 0 {
                bin = !bin;
            } else if num == 0 {
                return 0;
            }
        }
        return bin ? -1 : 1;
    }
}
// @lc code=end

