/*
 * @lc app=leetcode.cn id=1608 lang=swift
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
/*
 Accepted 2022-09-12
 98/98 (4 ms)
 Your runtime beats 100 % of swift submissions
 Your memory usage beats 31.25 % of swift submissions (14 MB)
*/
class Solution {
    func specialArray(_ nums: [Int]) -> Int {
        let numSize: Int = nums.count;
        var numsV: [Int] = nums;
        var pNum: Int = -1;

        numsV.sort(){$0 < $1;};

        for i in (1...numSize).reversed() {
            // print("\(numsV[numSize - i]) \(i)");
            if (numsV[numSize - i] >= i) {
                if (pNum >= i) {
                    return -1;
                } else {
                    return i;
                }
            }
            pNum = numsV[numSize - i];
        }

        return -1;
    }
}
// @lc code=end
/*
[0]\n
[0,0]\n
[3,5]\n
[0,4,3,0,4]\n
[3,6,7,7,0]
*/
