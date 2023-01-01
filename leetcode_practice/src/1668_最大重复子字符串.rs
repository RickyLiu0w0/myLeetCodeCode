/*
 * @lc app=leetcode.cn id=1668 lang=rust
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
/*
    Accepted 2022-11-03
    212/212 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 42.86 % of rust submissions (2.1 MB)
*/
use std::cmp;
impl Solution {
    pub fn max_repeating(sequence: String, word: String) -> i32 {
        let word_size = word.len();
        let mut begin = 0;
        let mut res = 0;
        let mut current_count = 0;
        let mut flag = false;

        while begin + word_size <= sequence.len() {
            if word == &sequence[begin..(begin + word_size)] {
                if !flag {
                    current_count = cmp::max(res, current_count);
                    res = 0;
                }
                res += 1;
                begin += word_size;
                flag = true;
            } else {
                if flag {
                    begin -= word_size;
                }
                begin += 1;
                flag = false;
            }
        }
        cmp::max(res, current_count)
    }
}

// @lc code=end
/*
""aaaaaaa"\n"a"\n
"aaaaaaa"\n"aa"\n
"aaaaaaa"\n"aaa"\n
"aaaaaaa"\n"aaaa"\n
"ababc"\n"ab"\n
"ababc"\n"ba"\n
"ababc"\n"ac"\n
"ababccabccababab"\n
"ab"\n
"abababccabccabab"\n
"ab"\n
"aaabaaaabaaabaaaabaaaabaaaabaaaaba"\n
"aaaba""
*/
