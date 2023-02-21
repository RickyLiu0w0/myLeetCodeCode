/*
 * @lc app=leetcode.cn id=1710 lang=rust
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
/**
    Accepted 2022-11-15
    76/76 (8 ms)
    Your runtime beats 66.67 % of rust submissions
    Your memory usage beats 33.33 % of rust submissions (2.2 MB)
*/
use std::cmp::Ordering;

impl Solution {
    pub fn maximum_units(mut box_types: Vec<Vec<i32>>, mut truck_size: i32) -> i32 {
        box_types.sort_by(|a, b| b.get(1).cmp(&a.get(1)));

        let mut res = 0;
        for box_type in box_types {
            if let Some(truck_num) = box_type.get(0) {
                res += match truck_size.cmp(&truck_num) {
                    Ordering::Greater | Ordering::Equal => {
                        truck_size -= truck_num;
                        truck_num
                            * match box_type.get(1) {
                                Some(x) => x,
                                _ => unreachable!(),
                            }
                    }

                    Ordering::Less => {
                        let tmp = truck_size;
                        truck_size = 0;
                        tmp
                            * match box_type.get(1) {
                                Some(x) => x,
                                _ => unreachable!(),
                            }
                    }
                };

                if truck_size == 0 {
                    return res;
                }
            }
        }
        res
    }
}
// @lc code=end
/*
[[5,10],[2,5],[4,7],[3,9]]\n100
*/
