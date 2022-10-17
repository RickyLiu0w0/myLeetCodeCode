/*
 * @lc app=leetcode.cn id=1652 lang=swift
 *
 * [1652] 拆炸弹
 */

// @lc code=start
/*
    Accepted 2022-09-24
    74/74 (8 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14 MB)
*/
class Solution {
    func decrypt(_ code: [Int], _ k: Int) -> [Int] {
        let size: Int = code.count;
        var res: [Int] = [];
        var sum: Int = 0;
        for index in 0..<size {
            sum = 0;
            if (k > 0) {
                for j in 1...k {
                    sum += code[(index + j) % size]
                }
            } else if (k < 0) {
                for j in 1...(-k) {
                    let temp: Int = index - j;
                    sum += code[temp < 0 ? size + temp : temp]
                }
            }
            res.append(sum);
        }
        return res;
    }
}
// @lc code=end
/*
[5,7,1,4]\n
3\n
[1,2,3,4]\n
0\n
[2,4,9,3]\n
-2
*/
