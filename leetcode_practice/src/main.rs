pub struct Solution;

impl Solution {
    pub fn greatest_letter(s: String) -> String {
        for c in ('A'..='Z').rev() {
            if s.contains(c) && s.contains(c.to_ascii_lowercase()) {
                return c.to_string();
            }
        }
        String::new()
    }
}

fn main() {
    println!("Hello, world!");
    println!("{}", Solution::greatest_letter(String::from("AAA")));
}
