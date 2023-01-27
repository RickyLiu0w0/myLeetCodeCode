/*
 * @lc app=leetcode.cn id=2309 lang=rust
 *
 * [2309] 兼具大小写的最好英文字母
 */

// @lc code=start
/*
    Accepted
    113/113 (8 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 60 % of rust submissions (2.1 MB)
 */
impl Solution {
    pub fn greatest_letter(s: String) -> String {
        for c in ('A'..='Z').rev() {
            if s.contains(c) && s.contains(c.to_ascii_lowercase()) {
                return c.to_string();
            }
        }
        String::new()
    }
}
// @lc code=end

