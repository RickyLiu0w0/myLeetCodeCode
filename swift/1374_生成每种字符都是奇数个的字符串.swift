/*
 * @lc app=leetcode.cn id=1374 lang=swift
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start
/*
    Accepted 2022-08-01 00:05
    103/103 (8 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (13.7 MB)
*/
class Solution {
    func generateTheString(_ n: Int) -> String {
        var res: String = "";
        if n % 2 == 0 {
            // 偶数
            res += "m";
        }

        let str: String = String(repeating: "j", count: n % 2 == 0 ? n - 1 : n);
        return res + str;

    }
}
// @lc code=end

