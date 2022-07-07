/*
 * @lc app=leetcode.cn id=1200 lang=swift
 *
 * [1200] 最小绝对差
 */

/*
    Accepted 2022-07-04 12:02
    37/37  (320 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (17.7 MB)
*/

// @lc code=start
class Solution {
    func minimumAbsDifference(_ arr: [Int]) -> [[Int]] {
        var minDifference : Int = Int.max;

        let afterSort = arr.sorted(by: {$0 < $1});

        for i in 1..<afterSort.count {
            if (afterSort[i] - afterSort[i - 1] < minDifference) {
                minDifference = afterSort[i] - afterSort[i - 1];
            }
        }

        var res: [[Int]] = [];
        for i in 1..<afterSort.count  {
            if (afterSort[i] - afterSort[i - 1] == minDifference) {
                res.append([afterSort[i - 1], afterSort[i]]);
            }
        }

        return res;
        
    }
}
// @lc code=end

/*
[4,2,1,3]\n
[1,3,6,10,15]\n
[3,8,-10,23,19,-4,-14,27]
*/

