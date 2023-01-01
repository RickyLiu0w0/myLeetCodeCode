/*
 * @lc app=leetcode.cn id=1684 lang=rust
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
/**
 * Accepted 2022-11-08
 * 74/74 (8 ms)
 * Your runtime beats 100 % of rust submissions
 * Your memory usage beats 100 % of rust submissions (2.6 MB)
 */
impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let mut set = vec![false; 26];
        let mut res = words.len() as i32;
        for &c in allowed.as_bytes() {
            // println!("{}", c - 97);
            set[(c as usize) - 97] = true;
        }

        for s in words.iter() {
            for &c in s.as_bytes() {
                if !set[(c as usize) - 97] {
                    res -= 1;
                    break;
                }
            }
        }
        res
    }
}
// @lc code=end
/*
"ab"\n["ad","bd","aaab","baa","badab"]\n
"abc"\n["a","b","c","ab","ac","bc","abc"]\n
"cad"\n["cc","acd","b","ba","bac","bad","ac","d"]
*/
