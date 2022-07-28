/*
 * @lc app=leetcode.cn id=1331 lang=swift
 *
 * [1331] 数组序号转换
 */

// @lc code=start
/*
    Accepted 2022-07-28 00:01
    38/38 (276 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (22.9 MB)
*/
class Solution {
    func arrayRankTransform(_ arr: [Int]) -> [Int] {
        let size = arr.count;
        if 0 == size {
            return [];
        }
        
        let arrSorted: [Int] = arr.sorted(by: {
            $0 < $1;
        });
        
        var counters: [Int: Int] = [arrSorted[0]:1];
        var counter: Int = 1;
        for index in 1..<size {
            if arrSorted[index - 1] == arrSorted[index] {
                // 两个相等，不统计
                continue;
            }
            counter += 1;
            counters[arrSorted[index]] = counter;
        }
        
        var res: [Int] = [];
        for num in arr {
            res.append(counters[num]!);
        }
        
        return res;
    }
}
// @lc code=end
/*
[40,10,20,30,20]\n
[100,100,100]\n
[]\n
[37,12,28,9,100,56,80,5,12]
*/
