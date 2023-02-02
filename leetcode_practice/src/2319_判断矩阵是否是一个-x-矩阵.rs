/*
 * @lc app=leetcode.cn id=2319 lang=rust
 *
 * [2319] 判断矩阵是否是一个 X 矩阵
 */

/*
    Accepted 2023-01-31
    84/84 (4 ms)
    Your runtime beats 75 % of rust submissions
    Your memory usage beats 50 % of rust submissions (2.3 MB)
 */

// @lc code=start
impl Solution {
    pub fn check_x_matrix(grid: Vec<Vec<i32>>) -> bool {
        // 对角线：grid[i][i] 以及 grid[i][n - i - 1]
        grid.into_iter().enumerate().all(|(i, vec)| {
            vec.iter()
                .enumerate()
                .all(|(j, &num)| (num == 0) ^ (i == j || i + j == vec.len() - 1))
        })
    }
}
// @lc code=end

