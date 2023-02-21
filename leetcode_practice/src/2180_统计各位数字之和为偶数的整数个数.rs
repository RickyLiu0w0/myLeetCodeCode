/*
 * @lc app=leetcode.cn id=2180 lang=rust
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

// @lc code=start
/*
    Accepted 2022-01-06
    71/71 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 0 % of rust submissions (2.1 MB)
 */
impl Solution {
    pub fn count_even(num: i32) -> i32 {
        let mut res = 0;
        for mut i in 1..=num {
            let mut sum = 0;
            while i != 0 {
                sum += i % 10;
                i /= 10;
            }

            if 0 == sum % 2 {
                res += 1;
            }
        }
        res
    }
}
// @lc code=end

