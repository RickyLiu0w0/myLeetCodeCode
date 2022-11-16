pub struct Solution;

impl Solution {
    pub fn interpret(command: String) -> String {
        command.split_inclusive(&['G', ')'][..]).map(|string| match string {
            "()" => "o",
            "(al)" => "al",
            _ => string,
        }).collect()
    }
}

fn main() {
    println!("Hello, world!");
    println!("{}", Solution::interpret("GGG()(al)".to_string()));
}
