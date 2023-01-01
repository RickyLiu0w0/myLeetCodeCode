/*
 * @lc app=leetcode.cn id=1678 lang=rust
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
/*
    Accepted 2022-11-06
    105/105 cases passed (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 16 % of rust submissions (2.2 MB)
 */
impl Solution {
    pub fn interpret(command: String) -> String {
        /*
         * G -> G
         * () -> o
         * (al) -> al
         * command.replace("(al)", "al").replace("()", "o")
         */
        let mut res = String::from("");
        let mut iter = command.chars();
        loop {
            res += match iter.next() {
                Some('G') => "G",
                Some('(') => {
                    match iter.next() {
                        Some(')') => "o",
                        Some('a') => {
                            // 跳过"l)"两个字符
                            iter.nth(1);
                            "al"
                        },
                        _ => unreachable!(),
                    }
                }
                _ => break,
            }
        }
        res
    }
}
// @lc code=end
/*
"G()(al)"\n
"G()()()()(al)"\n
"(al)G(al)()()G"
*/
