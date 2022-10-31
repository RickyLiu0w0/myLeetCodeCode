/*
 * @lc app=leetcode.cn id=1773 lang=swift
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
/*
    Accepted 2022-10-29
    92/92 (284 ms)
    Your runtime beats 40 % of swift submissions
    Your memory usage beats 60 % of swift submissions (15.6 MB)
*/
class Solution {
    func countMatches(_ items: [[String]], _ ruleKey: String, _ ruleValue: String) -> Int {
        var target = 0;
        var res = 0;
        if ruleKey == "color" {
            target = 1;
        } else if ruleKey == "name" {
            target = 2;
        }

        for item in items {
            if item[target] == ruleValue {
                res += 1;
            }
        }
        return res;
    }
}
// @lc code=end

