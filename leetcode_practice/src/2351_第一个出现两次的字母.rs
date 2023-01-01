/*
 * @lc app=leetcode.cn id=2351 lang=rust
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
/*
    Accepted 2023-01-01
    92/92 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 33.33 % of rust submissions (2.1 MB)
*/
use std::collections::HashSet; 
impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut dict: HashSet<char> = HashSet::new();
        for c in s.chars() {
            if dict.contains(&c) {
                return c;
            } else {
                dict.insert(c);
            }
        }
        unreachable!()
    }
}
// @lc code=end

