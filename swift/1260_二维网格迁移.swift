/*
 * @lc app=leetcode.cn id=1260 lang=swift
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
/*
    Accepted 2022-07-20 15:57
    107/107(148 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14.2 MB)
*/
class Solution {
    func shiftGrid(_ grid: [[Int]], _ k: Int) -> [[Int]] {
        let n: Int = grid[0].count;
        let m: Int = grid.count;
        let size: Int = m * n;
        let beginIndex: Int = size - (k % size == 0 ? size : k % size);
        if beginIndex == 0 {
            // 不用动
            return grid;
        }

        var indexGrid: Int = beginIndex;
        var rowRes: Int = 0;
        var colRes: Int = 0;
        var res: [[Int]] = [[Int]](repeating: [Int](repeating: 0, count: n), count: m);
        repeat {
            // grid[index] -> grid[rowGrid][colGrid]
            let rowGrid: Int = indexGrid / n;
            let colGrid: Int = indexGrid % n;
            res[rowRes][colRes] = grid[rowGrid][colGrid];
            indexGrid = indexGrid + 1 == size ? 0 : indexGrid + 1;
            
            if colRes + 1 == n {
                rowRes += 1;
                colRes = 0;
            } else {
                colRes += 1;
            }
            
        } while indexGrid != beginIndex;
        
        return res;
    }
}
// @lc code=end
/*
[[1,2,3],[4,5,6],[7,8,9]]\n
10\n
[[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n
87\n
[[1,2,3],[4,5,6],[7,8,9]]\n
36\n
[[1]]\n
100
*/
