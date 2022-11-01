/*
 * @lc app=leetcode.cn id=2006 lang=swift
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
/*
    Accepted 2022-11-01
    237/237 (24 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 33.33 % of swift submissions (14 MB)
*/
class Solution {
    func countKDifference(_ nums: [Int], _ k: Int) -> Int {
        var res = 0;
        let size = nums.count;
        var hash: [Int] = Array(repeating: 0, count: 101);

        // hash[i]统计i这个数在num之前出现过几次
        for num in nums {
            if num - k > 0 {
                // n-k这个数符合题意
                res += hash[num-k];
            }

            if num + k < 101 {
                // n+k这个数符合题意
                res += hash[num+k];
            }

            hash[num] += 1;
        }
        return res;
    }
}
// @lc code=end

