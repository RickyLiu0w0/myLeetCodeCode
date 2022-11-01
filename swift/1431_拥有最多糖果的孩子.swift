/*
 * @lc app=leetcode.cn id=1431 lang=swift
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
/*
    Accepted 2022-11-01
    103/103 (8 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 20 % of swift submissions (14 MB)
*/
class Solution {
    func kidsWithCandies(_ candies: [Int], _ extraCandies: Int) -> [Bool] {
        var max_candies = 0;
        candies.map{
            max_candies = $0 > max_candies ? $0 : max_candies;
        };
        var res: [Bool] = [];
        candies.map{
            res.append($0 + extraCandies >= max_candies);
        };
        return res;
    }
}
// @lc code=end

