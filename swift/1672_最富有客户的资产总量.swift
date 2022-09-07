/*
 * @lc app=leetcode.cn id=1672 lang=swift
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
/*
 Accepted 2022-09-04
 34/34 (24 ms)
 Your runtime beats 97.56 % of swift submissions
 Your memory usage beats 85.37 % of swift submissions (13.7 MB)
*/
class Solution {
    func maximumWealth(_ accounts: [[Int]]) -> Int {
        return accounts.map{$0.reduce(0,+)}.reduce(0, {max($0,$1)});
    }
}
// @lc code=end

