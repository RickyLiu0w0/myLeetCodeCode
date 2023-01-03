pub struct Solution;

impl Solution {
    pub fn are_numbers_ascending(s: String) -> bool {
        s.split_whitespace() // 按空格分割，返回SplitWhitespace类型
        .filter_map(|s| s.parse::<i32>().ok()) // 筛选数字，直接用ok取
        .collect::<Vec<_>>()
        .windows(2) // 2 大小的滑动床空
        .all(|x| x[0] < x[1]) // 所有都要符合严格递增
    }
}

fn main() {
    println!("Hello, world!");
    println!(
        "{}",
        Solution::are_numbers_ascending("sunset is at 7 51 pm overnights lows will be in the low 53 and 60".to_string())
    );
}
