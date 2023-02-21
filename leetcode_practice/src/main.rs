use std::collections::HashMap;

pub struct Solution;

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
fn main() {
    println!("Hello, world!");
    println!("{}", 2);
}
