/*
 * @lc app=leetcode.cn id=2469 lang=rust
 *
 * [2469] 温度转换
 */

// @lc code=start
/*
    Accepted 2023-01-27
    74/74 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 49.27 % of rust submissions (2 MB)
 */
impl Solution {
    pub fn convert_temperature(celsius: f64) -> Vec<f64> {
        vec![celsius + 273.15, celsius * 1.8 + 32.0]
    }
}
// @lc code=end

