pub struct Solution;

impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        let mut string1 = String::new();
        let mut string2 = String::new();
        for c in &word1 {
            string1.push_str(c);
        }
        for c in &word2 {
            string2.push_str(c);
        }
        string1 == string2
    }
}

fn main() {
    println!("Hello, world!");
}
