/*
 * @lc app=leetcode.cn id=1475 lang=swift
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
/*
    Accepted 2022-09-01
    103/103 (12 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 60 % of swift submissions (14.1 MB)
*/
class Solution {
    func finalPrices(_ prices: [Int]) -> [Int] {
        var res: [Int] = [];
        let size: Int = prices.count;
        for i in 0..<(size - 1) {
            let flagPrice: Int = prices[i];
            var j: Int = i + 1;
            while (j < size) {
                if (prices[j] <= flagPrice) {
                    res.append(flagPrice-prices[j]);
                    break;
                }
                j += 1;
            }

            if (size == j) {
                res.append(flagPrice);
            }
        }
        res.append(prices[size-1]);
        return res;
    }
}
// @lc code=end
/*
[8,4,6,2,3]\n
[1,2,3,4,5]\n
[10,1,1,6]\n
[1]\n
[100, 2]\n
*/
