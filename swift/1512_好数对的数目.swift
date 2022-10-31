/*
 * @lc app=leetcode.cn id=1512 lang=swift
 *
 * [1512] 好数对的数目
 */

// @lc code=start
/*
    Accepted 2022-10-11
    48/48 (4 ms)
    Your runtime beats 62.5 % of swift submissions
    Your memory usage beats 12.5 % of swift submissions (14.1 MB)
*/
class Solution {
    func numIdenticalPairs(_ nums: [Int]) -> Int {
        var res: Int = 0;
        for i in 0..<(nums.count-1) {
            for j in (i+1)..<nums.count {
                if nums[i] == nums[j] {
                    res += 1;
                }
            }
        }
        return res;
    }
}
// @lc code=end

