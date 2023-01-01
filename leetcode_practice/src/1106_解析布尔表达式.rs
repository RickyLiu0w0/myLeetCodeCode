/*
 * @lc app=leetcode.cn id=1106 lang=rust
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start
/*
    Accepted 2022-11-05
    75/75 (0 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 50 % of rust submissions (2 MB)
*/
impl Solution {
    pub fn parse_bool_expr(expression: String) -> bool {
        Solution::help(&expression[..])
    }

    fn help(expression: &str) -> bool {
        let mut char_iter = expression.chars();

        if let Some(c) = char_iter.nth(0) {
            let mut i = 2;
            let mut j = i + 1;
            let mut stack = 0;
            match c {
                'f' => false,

                't' => true,

                '!' => !Solution::help(&expression[i..(expression.len() - 1)]),

                '&' => {
                    char_iter.nth(1);
                    while j < expression.len() {
                        if let Some(c_j) = char_iter.nth(0) {
                            if c_j == '(' {
                                stack += 1;
                            } else if c_j == ')' {
                                stack -= 1;
                            } else if c_j == ',' && stack == 0 {
                                if !Solution::help(&expression[i..j]) {
                                    return false;
                                }

                                i = j + 1;
                            }
                        }
                        j += 1;
                    }
                    Solution::help(&expression[i..(j - 1)])
                }

                _ => {
                    char_iter.nth(1);
                    while j < expression.len() {
                        if let Some(c_j) = char_iter.nth(0) {
                            if c_j == '(' {
                                stack += 1;
                            } else if c_j == ')' {
                                stack -= 1;
                            } else if c_j == ',' && stack == 0 {
                                if Solution::help(&expression[i..j]) {
                                    return true;
                                }

                                i = j + 1;
                            }
                        }
                        j += 1;
                    }
                    Solution::help(&expression[i..(j - 1)])
                }
            }
        } else {
            false
        }
    }
}
// @lc code=end

