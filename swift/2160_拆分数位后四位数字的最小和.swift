/*
 * @lc app=leetcode.cn id=2160 lang=swift
 *
 * [2160] 拆分数位后四位数字的最小和
 */

// @lc code=start
/*
    Accepted 2022-09-25
    99/99 (0 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (13.5 MB)
*/
class Solution {
    func minimumSum(_ num: Int) -> Int {
        var numArray: [Int] = [];
        var numT: Int = num;
        for i in 0..<4 {
            numArray.append(numT % 10);
            numT /= 10;
        }

        numArray = numArray.sorted(){$0 < $1;};

        return (numArray[0] + numArray[1]) * 10 + numArray[2] + numArray[3];
    }
}
// @lc code=end

