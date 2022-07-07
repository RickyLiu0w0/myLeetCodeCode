/*
 * @lc app=leetcode.cn id=1217 lang=swift
 *
 * [1217] 玩筹码
 */

// @lc code=start
/*
    Accepted 2022-07-08 00:01
    51/51 (4 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 81.82 % of swift submissions (13.8 MB)
*/
class Solution {
    func minCostToMoveChips(_ position: [Int]) -> Int {
        var evenCount : Int = 0;
        
        for chip in position {
            if (0 == chip % 2) {
                // 偶数
                evenCount += 1;
            }
        }

        let oddCount : Int = position.count - evenCount;
        return oddCount < evenCount ? oddCount : evenCount;
    }
}

// @lc code=end

/*
[1,2,3]\n
[2,2,2,3,3]\n
[3,3,2,2,2]\n
[1,1000000000]\n
[1,2,3,4,5,3,3,4,3,2,4,1,1,1,3,4,5,6,7,3,3,2,45,6,13,13,1000000000,4,12]
*/