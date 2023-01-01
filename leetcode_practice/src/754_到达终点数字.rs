/*
 * @lc app=leetcode.cn id=754 lang=rust
 *
 * [754] 到达终点数字
 */

// @lc code=start
/*
    Accepted 2022-11-04
    73/73 cases passed (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 100 % of rust submissions (2.1 MB)
*/
impl Solution {
    pub fn reach_number(target: i32) -> i32 {
        let target = target.abs();
        let mut res = 1;
        loop {
            let sum = res * (res + 1) / 2;
            if sum == target || (sum > target && 0 == (sum - target) % 2) {
                return res;
            }
            res += 1;
        }
    }
}
// @lc code=end

