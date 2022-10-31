/*
 * @lc app=leetcode.cn id=1863 lang=swift
 *
 * [1863] 找出所有子集的异或总和再求和
 */

// @lc code=start
/*
    Accepted 2022-09-26
    48/48 (8 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14.3 MB)
*/
class Solution {
    func subsetXORSum(_ nums: [Int]) -> Int {
        // 计算子集
        var subSet: [[Int]] = [[]];
        for num in nums {
            let size: Int = subSet.count;
            for i in 0..<size {
                var temp: [Int] = subSet[i];
                temp.append(num);
                subSet.append(temp);
            }
        }

        // 计算异或
        var res: Int = 0;
        for sub in subSet {
            if sub.count == 0 {
                continue;
            }

            var xor: Int = sub[0];

            for i in 1..<sub.count {
                xor ^= sub[i];
            }

            res += xor;
        }
        
        return res;
    }
}
// @lc code=end

