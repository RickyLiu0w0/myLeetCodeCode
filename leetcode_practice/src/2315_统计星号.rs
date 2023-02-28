/*
 * @lc app=leetcode.cn id=2315 lang=rust
 *
 * [2315] 统计星号
 */

 /**
  Accepted 2023-01-29
  69/69 cases passed (0 ms)
  Your runtime beats 100 % of rust submissions
  Your memory usage beats 11.11 % of rust submissions (2.2 MB)
  */

// @lc code=start
impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        s.split('|')
            .enumerate() // 枚举出索引号 
            .filter(|(idx, _)| (*idx + 1) % 2 == 1) // 偶数下标
            .map(|(_, s)| s.as_bytes().iter().filter(|&&b| b == b'*').count() as i32)
            .sum()
    }
}
// @lc code=end

