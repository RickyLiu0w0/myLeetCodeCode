pub struct Solution;

impl Solution {
    pub fn count_even(num: i32) -> i32 {
        let mut res = 0;
        for mut i in 1..=num {
            let mut sum = 0;
            while i != 0 {
                sum += i % 10;
                i /= 10;
            }

            if 0 == sum % 2 {
                res += 1;
            }
        }
        res
    }
}

fn main() {
    println!("Hello, world!");
    println!("{}", Solution::count_even(30));
}
