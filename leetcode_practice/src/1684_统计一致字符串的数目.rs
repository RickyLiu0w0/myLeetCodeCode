/*
 * @lc app=leetcode.cn id=1684 lang=rust
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
use std::collections::HashSet;

impl Solution {
    pub fn count_consistent_strings(allowed: String, mut words: Vec<String>) -> i32 {
        let set: HashSet<char> = allowed.chars().collect();
        words.retain(|word| word.chars().all(|c| set.contains(&c)));
        words.len() as i32
    }
}

// @lc code=end

