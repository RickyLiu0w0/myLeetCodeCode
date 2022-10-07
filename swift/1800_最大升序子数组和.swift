/*
 * @lc app=leetcode.cn id=1800 lang=swift
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start
/*
    Accepted
    104/104 (8 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14 MB)
*/
class Solution {
    func maxAscendingSum(_ nums: [Int]) -> Int {
        var res: Int = nums[0];
        var sum: Int = nums[0];
        let size: Int = nums.count;
        for i in 1..<size {
            if nums[i-1] < nums[i] {
                sum += nums[i];
            } else {
                res = res < sum ? sum : res;
                sum = nums[i];
            }
        }

        return res < sum ? sum : res;
    }
}
// @lc code=end
/*
[10,20,30,5,10,50]\n
[10,20,30,40,50]\n
[12,17,15,13,10,11,12]\n
[100,10,1]\n
[1,11,12]
*/
