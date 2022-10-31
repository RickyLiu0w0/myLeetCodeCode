/*
 * @lc app=leetcode.cn id=1790 lang=swift
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
/*
    Accepted 2022-10-11
    131/131 (0 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (13.9 MB)
*/
class Solution {
    func areAlmostEqual(_ s1: String, _ s2: String) -> Bool {
        if s1 == s2 {
            return true;
        }

        let c1: Array = Array(s1);
        let c2: Array = Array(s2);
        var s1Diff1: Character? = nil;
        var s2Diff1: Character = Character("\n");
        var res: Bool = false;
        
        for index in 0..<c1.count {
            if c1[index] != c2[index] {
                if nil == s1Diff1 {
                    s1Diff1 = c1[index];
                    s2Diff1 = c2[index];
                } else {
                    if res || c1[index] != s2Diff1 || s1Diff1 != c2[index] {
                        return false;
                    }
                    res = true;
                }
            }
        }

        return res;
    }
}
// @lc code=end
/*
""bank"\n
"kanb"\n
"attack"\n
"defend"\n
"kelb"\n
"kelb"\n
"abcd"\n
"dcba"\n
"yhy"\n
"hyc"\n
"yhc"\n
"hyy"\n
"qgqeg"\n
"gqgeq"\n
"kelb"\n
"kelb"\n
"aa"\n
"ac"\n
"npv"\n
"zpn"\n
"baaa"\n
"abbb""
*/
