pub struct Solution;

use std::collections::HashSet; 
impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut dict: HashSet<char> = HashSet::new();
        for c in s.chars() {
            if dict.contains(&c) {
                return c;
            } else {
                dict.insert(c);
            }
        }
        unreachable!()
    }
}

fn main() {
    println!("Hello, world!");
    println!("{}", Solution::repeated_character("seself".to_string()));
}
