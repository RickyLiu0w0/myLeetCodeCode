/*
 * @lc app=leetcode.cn id=1784 lang=swift
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
/*
    Accepted 2022-10-01
    191/191 (4 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (13.9 MB)
*/
class Solution {
    func checkOnesSegment(_ s: String) -> Bool {
    /*
        var state: Bool = true;

        for c in s {
            if ("0" == c) {
                state = false;
            } else {
                if (!state) {
                    return false;
                }
            }
        }

        return true;
    */

        // 考虑前导0存在
        var state: Int = 0;
        for c in s {
            switch state {
                case 0:
                    if "1" == c {
                        state = 1;
                    }
                case 1:
                    if "0" == c {
                        state = 2;
                    }
                case 2:
                    if "1" == c {
                        return false;
                    }
                default:
                    return false;
            }
        }
        return true;
        
    }
}
// @lc code=end

