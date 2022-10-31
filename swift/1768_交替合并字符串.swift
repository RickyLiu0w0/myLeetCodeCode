/*
 * @lc app=leetcode.cn id=1768 lang=swift
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
/*
    Accepted 2022-10-23
    108/108 (8 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (13.8 MB)
*/
class Solution {
    func mergeAlternately(_ word1: String, _ word2: String) -> String {
        // let word1: [UInt8] = Array(word1.utf8);
        // let word2: [UInt8] = Array(word2.utf8);
        var res: String = "";
        var p1 = 0;
        var p2 = 0;
        let size1 = word1.count;
        let size2 = word2.count;
        while p1 < size1 {
            res.append(word1[word1.index(word1.startIndex, offsetBy: p1)]);
            p1 += 1;
            if p2 == size2 {
                // word2已经处理完
                res += word1[word1.index(word1.startIndex, offsetBy: p1)..<word1.endIndex]
                break;
            } else {
                res.append(word2[word2.index(word2.startIndex, offsetBy: p2)]);
                p2 += 1;
            }
        }

        if p1 == size1 {
            res += word2[word2.index(word2.startIndex, offsetBy: p2)..<word2.endIndex]
        }
        return res;
    }
}
// @lc code=end
/*
"abc"\n"pqr"\n
"ab"\n"pqrs"\n
"abcd"\n"pq"\n
*/
