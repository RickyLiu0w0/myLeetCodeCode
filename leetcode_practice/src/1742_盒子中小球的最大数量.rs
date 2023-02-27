/*
 * @lc app=leetcode.cn id=1742 lang=rust
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
/*
    Accepted 2022-11-23
    97/97 (36 ms)
    Your runtime beats 16.67 % of rust submissions
    Your memory usage beats 66.67 % of rust submissions (2.1 MB)
*/
use std::collections::HashMap;
impl Solution {
    pub fn count_balls(low_limit: i32, high_limit: i32) -> i32 {
        let mut counter = HashMap::new();
        for num in low_limit..=high_limit {
            let str = num.to_string();
            let count = counter
            .entry(str.chars().fold(0, |sum, x| -> usize { sum + if let Some(dig) = x.to_digit(10) {
                dig as usize
            } else {
                0_usize
            }}))
            .or_insert(0);
            *count += 1;
        }
        
        if let Some(res) = counter
        .into_iter()
        .max_by(|a,b| a.1.cmp(&b.1))
        .map(|(_k, v)| v) {
            res
        } else {
            unreachable!();
        }
    }
}
// @lc code=end

