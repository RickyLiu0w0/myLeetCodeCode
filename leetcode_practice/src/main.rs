pub struct Solution;

impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        s.split('|')
            .enumerate() // 枚举出索引号 
            .filter(|(idx, _)| (*idx + 1) % 2 == 1) // 偶数下标
            .map(|(_, s)| s.as_bytes().iter().filter(|&&b| b == b'*').count() as i32)
            .sum()
    }
}
fn main() {
    println!("Hello, world!");
    println!(
        "{:#?}",
        Solution::count_asterisks(String::from("l|*e*et|c**o|*de|"))
    );
}
