/*
 * @lc app=leetcode.cn id=1832 lang=rust
 *
 * [1832] 判断句子是否为全字母句
 */

/*
    Accepted 2023-02-01
    79/79 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 60.81 % of rust submissions (2 MB)
 */

// @lc code=start
impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        0b11111111111111111111111111 == sentence.as_bytes()
        .into_iter()
        .fold(0, |acc, c| acc | (1 << (c - b'a')))
    }
}
// @lc code=end

