/*
 * @lc app=leetcode.cn id=1694 lang=swift
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
/*
    Accepted 2022-09-30
    108/108 (8 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14.1 MB)
*/
class Solution {
    func reformatNumber(_ number: String) -> String {
        var numCount: Int = 0;
        var res: String = "";
        for c in number {
            if (c != " " && "-" != c) {
                numCount += 1;
                res.append(c);
            }
        }
        // print("\(numCount)")

        var offset: Int = 0;
        while (numCount > 4) {
                offset += 3;
                res.insert("-", at: res.index(res.startIndex, offsetBy: offset));
                offset += 1;
                numCount -= 3;    
        }

        if (numCount == 4) {
            offset += 2;
            res.insert("-", at: res.index(res.startIndex, offsetBy: offset));
        }
        return res;
    }
}
// @lc code=end
/*
""1-23 4 --56"\n
"1-23 4 --567"\n
"1   2"\n
"1--3-3-"\n
"1-23 4 --567  8"\n
"123 4-56780"\n
"--17-5 229 35-39475 ""
*/
