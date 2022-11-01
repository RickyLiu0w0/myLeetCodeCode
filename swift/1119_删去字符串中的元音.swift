/*
 * @lc app=leetcode.cn id=1119 lang=swift
 *
 * [1119] 删去字符串中的元音
 */

// @lc code=start
/*
    Accepted 2022-11-01
    21/21 (4 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (15 MB)
*/
class Solution {
    func removeVowels(_ s: String) -> String {
        let vowels: Set<String> = ["a", "e", "i", "o", "u"];
        var sV = s;
        for c in vowels {
            sV = sV.replacingOccurrences(of: c, with: "");
        }
        return sV;
    }
}
// @lc code=end

