/*
 * @lc app=leetcode.cn id=2363 lang=rust
 *
 * [2363] 合并相似的物品
 */

/*
    Accepted 2023-02-28
    49/49 cases passed (4 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 14.29 % of rust submissions (2.4 MB)
*/

// @lc code=start
use std::{collections::HashMap, vec};

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

