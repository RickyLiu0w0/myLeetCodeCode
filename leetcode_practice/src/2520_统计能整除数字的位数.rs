/*
 * @lc app=leetcode.cn id=2520 lang=rust
 *
 * [2520] 统计能整除数字的位数
 */

 /**
    Accepted 2023-01-03
    56/56 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 88.57 % of rust submissions (2 MB)
  */
// @lc code=start
impl Solution {
    pub fn count_digits(num: i32) -> i32 {
        let mut n = num;
        let mut res = 0;

        while 0 != n {
            if 0 == num % (n % 10 ) {
                res += 1;
            }
            n /= 10;
        }
        res
    }
}
// @lc code=end

