/*
 * @lc app=leetcode.cn id=2042 lang=rust
 *
 * [2042] 检查句子中的数字是否递增
 */

/*
    Accepted 2023-01-03
    98/98 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 77.78 % of rust submissions (2 MB)
*/

// @lc code=start
impl Solution {
    pub fn are_numbers_ascending(s: String) -> bool {
        s.split_whitespace() // 按空格分割，返回SplitWhitespace类型
            .filter_map(|s| s.parse::<i32>().ok()) // 筛选数字，直接用ok取
            .collect::<Vec<_>>()
            .windows(2) // 2 大小的滑动窗口
            .all(|x| x[0] < x[1]) // 所有都要符合严格递增
    }
}
// @lc code=end
