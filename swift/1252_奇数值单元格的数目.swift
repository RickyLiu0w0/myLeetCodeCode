/*
 * @lc app=leetcode.cn id=1252 lang=swift
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start
/*
    Accepted 2022-07-12
    44/44 (8 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 50 % of swift submissions (13.9 MB)
*/
class Solution {
    func oddCells(_ m: Int, _ n: Int, _ indices: [[Int]]) -> Int {
        var matrix: [Int] = Array(repeating: 0, count: m * n);
        for indice in indices {
            // 对行加
            for col in 0..<n {
                matrix[indice[0] * n + col] += 1;
            }
            
            // 对列加
            for raw in 0..<m {
                matrix[raw * n + indice[1]] += 1;
            }
        }
        
        var res: Int = 0;
        for item in matrix {
            if (0 != item % 2) {
                // 奇数
                res += 1;
            }
        }
        return res;
    }
}
// @lc code=end
/*
2\n
3\n
[[0,1],[1,1]]\n
2\n
2\n
[[1,1],[0,0]]
*/
