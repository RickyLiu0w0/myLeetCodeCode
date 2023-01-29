/*
 * @lc app=leetcode.cn id=2535 lang=rust
 *
 * [2535] 数组元素和与数字和的绝对差
 */

// @lc code=start
/**
    Accepted 2023-01-27
    142/142  (4 ms)
    Your runtime beats 36.11 % of rust submissions
    Your memory usage beats 13.89 % of rust submissions (2.2 MB)
*/
impl Solution {
    pub fn difference_of_sum(nums: Vec<i32>) -> i32 {
        nums.into_iter()
        .fold(0, |acc, x| -> i32 {
            if x >= 10 {
                let mut temp = 0;
                let mut x_temp = x;
                while x_temp != 0 {
                    temp += x_temp % 10;
                    x_temp /= 10;
                }
                acc + x - temp
            } else {
                acc
            }
        })
    }
}
// @lc code=end

