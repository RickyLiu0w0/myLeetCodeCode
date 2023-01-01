/*
 * @lc app=leetcode.cn id=1221 lang=swift
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
/*
* Accepted 2022-10-31
* 40/40 (0 ms)
* Your runtime beats 100 % of swift submissions
* Your memory usage beats 28.57 % of swift submissions (14 MB)
*/
class Solution {
    func balancedStringSplit(_ s: String) -> Int {
        var r = 0;
        var l = 0;
        var res = 0;
        for c in s {
            if c == "L" {
                l += 1;
            } else {
                r += 1;
            }

            if l == r {
                l = 0;
                r = 0;
                res += 1;
            }
        }
        return res;
    }
}
// @lc code=end

