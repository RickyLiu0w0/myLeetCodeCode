use std::{collections::HashMap, vec};

pub struct Solution;

impl Solution {
    pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut map: HashMap<i32, i32> = HashMap::new();
        for item in &items1 {
            map.insert(item[0], item[1]);
        }

        for item in &items2 {
            let count = map.entry(item[0]).or_insert(0);
            *count += item[1];
        }

        let mut res = Vec::new();

        for (&key, &val) in map.iter() {
            res.push(vec![key, val]);
        }

        res.sort_by_key(|num| num[0]);
        res
    }
}

// @lc code=end
fn main() {
    println!("Hello, world!");
    println!("{:?}", Solution::merge_similar_items(vec![vec![1,1], vec![4, 5], vec![3, 8]], vec![vec![3,1], vec![1,5]]));
}
