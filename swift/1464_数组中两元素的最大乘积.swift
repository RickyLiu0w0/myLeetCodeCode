/*
 * @lc app=leetcode.cn id=1464 lang=swift
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
/*
Accepted 2022-08-26
104/104  (16 ms)
Your runtime beats 100 % of swift submissions
Your memory usage beats 28.57 % of swift submissions (13.8 MB)
*/
class Solution {
    func maxProduct(_ nums: [Int]) -> Int {
        // 题目转化为寻找数组中最大的两个数
        let flag: Bool = nums[0] > nums[1];
        let numSize: Int = nums.count;
        var maxNum: Int = flag ? nums[0] : nums[1];
        var secMaxNum: Int = flag ? nums[1]: nums[0];

        for i in 2..<numSize {
            if (nums[i] >= maxNum) {
                secMaxNum = maxNum;
                maxNum = nums[i];
            } else {
                if (nums[i] > secMaxNum) {
                    secMaxNum = nums[i];
                }
            }
        }

        return (maxNum - 1) * (secMaxNum - 1);
    }
}
// @lc code=end

/*
[3,4,5,2]\n
[1,5,4,5]\n
[3,7]\n
[10,2,5,2]
*/
