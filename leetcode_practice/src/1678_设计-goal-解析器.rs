/*
 * @lc app=leetcode.cn id=1678 lang=rust
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
impl Solution {
    pub fn interpret(command: String) -> String {
        command.split_inclusive(&['G', ')'][..]).map(|string| match string {
            "()" => "o",
            "(al)" => "al",
            _ => string,
        }).collect()
    }
}
// @lc code=end

