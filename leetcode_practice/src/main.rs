use std::collections::HashSet;

pub struct Solution;

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        nums.iter()
        .filter(|&&num| num != 0)
        .collect::<std::collections::HashSet<_>>()
        .len() as i32
        
    }
}
// @lc code=end
fn main() {
    println!("Hello, world!");
    println!("{:?}", Solution::minimum_operations(vec![1,0,5,0,3,5])); // 插入 (3, "ccccc")，返回 []
}
