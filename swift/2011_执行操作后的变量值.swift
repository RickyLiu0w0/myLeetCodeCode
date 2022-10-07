/*
 * @lc app=leetcode.cn id=2011 lang=swift
 *
 * [2011] 执行操作后的变量值
 */

// @lc code=start
/*
    Accepted 2022-09-12
    259/259 cases passed (20 ms)
    Your runtime beats 88.89 % of swift submissions
    Your memory usage beats 33.33 % of swift submissions (14.4 MB)
*/
class Solution {
    func finalValueAfterOperations(_ operations: [String]) -> Int {
        // 其实判断中间的符号就可以了
        var X: Int = 0;
        operations.map{
            if ($0[$0.index($0.startIndex, offsetBy: 1)] == "+") {
                X += 1;
            } else {
                X -= 1;
            }
        };
        return X;
    }
}
// @lc code=end
/*
["--X","X++","X++"]\n
["++X","++X","X++"]\n
["X++","++X","--X","X--"]
*/
