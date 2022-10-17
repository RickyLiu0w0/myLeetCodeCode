/*
 * @lc app=leetcode.cn id=1486 lang=swift
 *
 * [1486] 数组异或操作
 */

// @lc code=start
/*
    Accepted 2022-09-24
    54/54 (0 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (13.4 MB)
*/
class Solution {
    func xorOperation(_ n: Int, _ start: Int) -> Int {
        var res: Int = start;
        for i in 1..<n {
            res ^= start + 2 * i;
        }
        return res;
    }
}
// @lc code=end
/*
5\n
0\n
4\n
3\n
1\n
7\n
10\n
5\n
*/
