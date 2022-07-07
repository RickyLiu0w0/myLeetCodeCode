/*
 * @lc app=leetcode.cn id=1920 lang=swift
 *
 * [1920] 基于排列构建数组
 */

/**
 * Accepted 2022-07-01 13:28
 * 140/140 cases passed (76 ms)
 * Your runtime beats 90.9 % of swift submissions
 * Your memory usage beats 90.9 % of swift submissions (14 MB)
 */

// @lc code=start
class Solution {
    func buildArray(_ nums: [Int]) -> [Int] {
        var resArray: [Int]! = [];

        for index in 0..<nums.count {
            resArray.append(nums[nums[index]]);
        }

        return resArray;
    }
}
// @lc code=end

/*
[5,0,1,2,3,4]\n
[0,2,1,5,3,4]
*/