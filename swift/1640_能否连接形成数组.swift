/*
 * @lc app=leetcode.cn id=1640 lang=swift
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
/* 2022-09-22
    84/84 (12 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 33.33 % of swift submissions (14.1 MB)
*/
class Solution {
    func canFormArray(_ arr: [Int], _ pieces: [[Int]]) -> Bool {
        let piecesC: Int = arr.count - 1;
        for piecess in pieces {
            if let begin = arr.firstIndex(of: piecess[0]) {
                let size: Int = piecess.count;
                for i in 1..<size {
                    if begin == piecesC || arr[begin + i] != piecess[i] {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
/*
[85]\n
[[85]]\n
[85]\n
[[86]]\n
[15,88]\n
[[88],[15]]\n
[49,18,16]\n
[[16,18,49]]\n
[91,4,64,78]\n
[[78],[4,64],[91]]
*/
