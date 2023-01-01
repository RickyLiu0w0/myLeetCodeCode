/*
 * @lc app=leetcode.cn id=2037 lang=rust
 *
 * [2037] 使每位学生都有座位的最少移动次数
 */

// @lc code=start
/*
    Accepted 2022-12-31
    262/262 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 12.5 % of rust submissions (2.1 MB)
 */
impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>,mut students: Vec<i32>) -> i32 {
        seats.sort();
        students.sort();
        seats.into_iter()
        .zip(students.into_iter()) // 将两个数组组合起来成一个元组 
        .fold(0, |acc, (seat, student)| acc + (seat - student).abs())
    }
}
// @lc code=end

