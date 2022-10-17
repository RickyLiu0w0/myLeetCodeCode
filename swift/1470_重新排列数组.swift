/*
 * @lc app=leetcode.cn id=1470 lang=swift
 *
 * [1470] 重新排列数组
 */

// @lc code=start
/*
    Accepted 2022-08-29 9:18
    53/53 (28 ms)
    Your runtime beats 42.86 % of swift submissions
    Your memory usage beats 28.57 % of swift submissions (14.2 MB)
*/
class Solution {
    func shuffle(_ nums: [Int], _ n: Int) -> [Int] {
        var res: [Int]  = [];
        var secPos: Int = n;

        for firPos in 0..<n {
            res.append(nums[firPos]);
            res.append(nums[secPos]);
            secPos += 1;
        }

        return res;
    }
}
// @lc code=end

/*
[2,5,1,3,4,7]\n
3\n
[1,2,3,4,4,3,2,1]\n
4\n
[1,1,2,2]\n
2
*/
