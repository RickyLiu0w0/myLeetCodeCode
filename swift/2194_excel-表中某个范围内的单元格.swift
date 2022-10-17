/*
 * @lc app=leetcode.cn id=2194 lang=swift
 *
 * [2194] Excel 表中某个范围内的单元格
 */

// @lc code=start
/*
    Accepted 2022-09-28
    251/251 (16 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14.1 MB)
*/
class Solution {
    func cellsInRange(_ s: String) -> [String] {
        let beginCol: Int = Int(s.character(at: 0));
        let beginRow: Int = Int(s.character(at: 1));
        let endCol: Int = Int(s.character(at: 3));
        let endRow: Int = Int(s.character(at: 4));
        var res: [String] = [];

        for col in beginCol...endCol {
            for row in beginRow...endRow {
                var str: String = "";
                str.append(Character(UnicodeScalar(col)!));
                str.append(Character(UnicodeScalar(row)!));
                res.append(str);
            }
        }
        return res;
    }
}
// @lc code=end

