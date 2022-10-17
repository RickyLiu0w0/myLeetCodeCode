/*
 * @lc app=leetcode.cn id=1624 lang=swift
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
/*
    Accepted 2022-09-17
    54/54 (4 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14.4 MB)
*/
class Solution {
    func maxLengthBetweenEqualCharacters(_ s: String) -> Int {
        var res: Int = -1;
        var dic: [Character: Int] = [:];
        var index: Int = 0;

        for c in s {
            if let val = dic[c] {
                // 找到
                let length: Int = index - val - 1;
                res = length > res ? length : res;
            } else {
                // 没找到
                dic.updateValue(index, forKey: c);
            }

            index += 1;
        }

        return res;
    }
}
// @lc code=end
/*
""aa"\n
"abca"\n
"cbzxg"\n
"cabbac"\n
"abaiutbbbb""
*/
