/*
 * @lc app=leetcode.cn id=1636 lang=swift
 *
 * [1636] 按照频率将数组升序排序
 */

// @lc code=start
/*
    Accepted 2022-09-19
    180/180 (16 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14 MB)
*/
class Solution {
    func frequencySort(_ nums: [Int]) -> [Int] {
        var dic: [Int: Int] = [:];
        for num in nums {
            if let v = dic[num] {
                dic[num] = v + 1;
            } else {
                dic[num] = 1;
            }
        }

        let values = dic.sorted(by: {return ($0.1 == $1.1) ? ($0.0 > $1.0) : ($0.1 < $1.1)});
        var res: [Int] = [];
        for (key, val) in values {
            for c in 0..<val {
                res.append(key);
            }
        }
        return res;
    }
}
// @lc code=end
/*
[1,1,2,2,2,3]\n
[2,3,1,3,2]\n
[-1,1,-6,4,5,-6,1,4,1]
*/
