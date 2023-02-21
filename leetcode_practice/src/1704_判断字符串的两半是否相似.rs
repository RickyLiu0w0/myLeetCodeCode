/*
 * @lc app=leetcode.cn id=1704 lang=rust
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
/*
    Accepted 2022-11-11
    113/113 cases passed (4 ms)
    Your runtime beats 14.29 % of rust submissions
    Your memory usage beats 71.43 % of rust submissions (2.1 MB)
 */
use std::collections::{HashSet};

impl Solution {
    pub fn halves_are_alike(s: String) -> bool {
        let set = HashSet::from(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
        Solution::count_vowel(&s[..(s.len() / 2)], &set) == Solution::count_vowel(&s[(s.len() / 2)..], &set)
    }

    fn count_vowel(s: &str, set: &HashSet<char>) -> usize {
        /*s.chars()
        .filter(|c| set.contains(&c))
        .count()*/
        
        s.chars()
        .fold(0, |mut count, c| {
            if set.contains(&c) {
                count += 1;
            }
            count
        })
        
    }
}
// @lc code=end

