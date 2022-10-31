/*
 * @lc app=leetcode.cn id=1662 lang=rust
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
/*
    Accepted 2022-11-01
    110/110 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 10 % of rust submissions (2.2 MB)
 */
impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        /*let mut string1 = String::new();
        let mut string2 = String::new();
        for c in &word1 {
            string1.push_str(c);
        }
        for c in &word2 {
            string2.push_str(c);
        }
        string1 == string2*/

        word1.concat() == word2.concat()
    }
}
// @lc code=end

