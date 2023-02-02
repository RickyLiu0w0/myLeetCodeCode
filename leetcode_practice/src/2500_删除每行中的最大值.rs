/*
 * @lc app=leetcode.cn id=2500 lang=rust
 *
 * [2500] 删除每行中的最大值
 */

/*
    Accepted 2023-01-31
    55/55 (4 ms)
    Your runtime beats 63.64 % of rust submissions
    Your memory usage beats 21.21 % of rust submissions (2.2 MB)
 */

// @lc code=start
impl Solution {
    pub fn delete_greatest_value(mut grid: Vec<Vec<i32>>) -> i32 {
        for v in grid.iter_mut() {
            v.sort_unstable_by(|x,y| y.cmp(x));
        }
        
        let n = grid.first().unwrap().len(); // let n = grid[0].len();
        
        let mut res = 0;
        for j in 0..n {
            res += grid.iter().map(|row| row[j]).max().unwrap();
        }
        res
    }
}
// @lc code=end

