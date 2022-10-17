/*
 * @lc app=leetcode.cn id=2114 lang=swift
 *
 * [2114] 句子中的最多单词数
 */

// @lc code=start
/*
    Accepted 2022-09-12
    90/90(40 ms)
    Your runtime beats 50 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14.3 MB)
*/
class Solution {
    func mostWordsFound(_ sentences: [String]) -> Int {
        return sentences.map {
            var count: Int = 1;
            for character in $0 {
                if character == " " {
                    count += 1;
                }
            }
            return count;
        }.reduce(0) {max($0, $1);};
    }
}
// @lc code=end
/*
["alice and bob love leetcode", "i think so too", "this is great thanks very much"]\n
["please wait", "continue to fight", "continue to win"]
*/
