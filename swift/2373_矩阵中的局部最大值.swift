/*
 * @lc app=leetcode.cn id=2373 lang=swift
 *
 * [2373] 矩阵中的局部最大值
 */

// @lc code=start
/*
    Accepted 2022-09-27
    50/50 (80 ms)
    Your runtime beats 87.5 % of swift submissions
    Your memory usage beats 50 % of swift submissions (14.2 MB)
*/
class Solution {
    func largestLocal(_ grid: [[Int]]) -> [[Int]] {
        let row_col: Int = grid.count;
        var res: [[Int]] = Array(repeating: Array(repeating: 0, count: row_col - 2), count: row_col - 2);
        for r in 1..<(row_col - 1) {
            for c in 1..<(row_col - 1) {
                res[r - 1][c - 1] = largestLocalHelp(grid, r, c);
            }
        }
        return res;
    }
    
    func largestLocalHelp(_ grid: [[Int]], _ row: Int, _ col: Int) -> Int {
        // 在一个3x3的矩阵内求最大值
        var res: Int = 0;
        for r in (row - 1)...(row + 1) {
            for c in (col - 1)...(col + 1) {
                res = res > grid[r][c] ? res : grid[r][c];
            }
        }

        return res;
    }
}
// @lc code=end
/*
[[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]\n
[[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
*/
