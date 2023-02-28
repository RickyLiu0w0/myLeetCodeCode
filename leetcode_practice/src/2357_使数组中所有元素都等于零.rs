/*
 * @lc app=leetcode.cn id=2357 lang=rust
 *
 * [2357] 使数组中所有元素都等于零
 */

/*
    Accepted 2023-02-24
    95/95 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 50 % of rust submissions (2 MB)
 */

// @lc code=start
impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        nums.iter()
        .filter(|&&num| num != 0)
        .collect::<std::collections::HashSet<_>>()
        .len() as i32
        
    }
}
// @lc code=end

