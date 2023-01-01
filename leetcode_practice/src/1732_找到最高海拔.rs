/*
 * @lc app=leetcode.cn id=1732 lang=rust
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
/*
    Accepted 2022-11-19
    80/80 cases passed (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 20 % of rust submissions (2.1 MB)
 */
impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut res = 0;
        gain.into_iter().fold(0, |a,b| {
            let temp = a + b;
            if temp > res {
                res = temp;
            }
            temp
        });
        res
    }
}
// @lc code=end

