/*
 * @lc app=leetcode.cn id=771 lang=swift
 *
 * [771] 宝石与石头
 */

// @lc code=start
/*
    Accepted 2022-09-26
    255/255 (4 ms)
    Your runtime beats 66.67 % of swift submissions
    Your memory usage beats 55.56 % of swift submissions (14 MB)
*/
class Solution {
    func numJewelsInStones(_ jewels: String, _ stones: String) -> Int {
        var res: Int = 0;
        stones.map{
            if jewels.contains($0) {
                res += 1;
            }
        };
        return res;
    }
}
// @lc code=end
/*
"aA"\n
"aAAbbbb"\n
"z"\n
"ZZ"
*/
