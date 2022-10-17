/*
 * @lc app=leetcode.cn id=1598 lang=swift
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
/*
 Accepted 2022-09-09
 99/99 (12 ms)
 Your runtime beats 100 % of swift submissions
 Your memory usage beats 100 % of swift submissions (14.4 MB)
*/
class Solution {
    func minOperations(_ logs: [String]) -> Int {
        var res: Int = 0;
        for log in logs {
            if ("../" == log) {
                res = (res == 0) ? 0 : res - 1;
            } else if ("./" == log) {
                continue;
            } else {
                res += 1;
            }
        }
        return res;
    }
}
// @lc code=end
/*
["d1/","d2/","../","d21/","./"]\n
["d1/","d2/","./","d3/","../","d31/"]\n
["d1/","../","../","../"]
*/
