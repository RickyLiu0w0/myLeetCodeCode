/*
 * @lc app=leetcode.cn id=2325 lang=rust
 *
 * [2325] 解密消息
 */

/*
    Accepted 2023-02-01
    69/69 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 80 % of rust submissions (2 MB)
 */

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn decode_message(key: String, message: String) -> String {
        let mut dict: HashMap<char, char> = HashMap::new();
        let mut char_index = 'a' as u8;
        for c in key.chars() {
            if c.is_ascii_lowercase() {
                char_index += match dict.get(&c) {
                    Some(_) => 0,
                    None => {
                        dict.insert(c, char_index as char);
                        1
                    },
                }
            }
        }
        dict.insert(' ', ' ');
        let mut res = String::new();
        for c in message.chars() {
            if let Some(decode_char) = dict.get(&c) {
                res.push(*decode_char);
            }
        }
        res
    }
}
// @lc code=end

