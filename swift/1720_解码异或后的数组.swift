/*
 * @lc app=leetcode.cn id=1720 lang=swift
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
/*
 Accepted 2022-09-07
 76/76 (184 ms)
 Your runtime beats 100 % of swift submissions
 Your memory usage beats 100 % of swift submissions (15.3 MB)
*/
class Solution {
    func decode(_ encoded: [Int], _ first: Int) -> [Int] {
        var res: [Int] = [first];
        var i: Int = 0;
        for num in encoded {
            res.append(res[i] ^ num);
            i += 1;
        }
        return res;
    }
}
// @lc code=end
/*
[1,2,3]\n
1\n
[6,2,7,3]\n
4
*/
