/*
 * @lc app=leetcode.cn id=1184 lang=swift
 *
 * [1184] 公交站间的距离
 */

// @lc code=start
/*
    37/37 (16 ms) 2022-07-24
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 50 % of swift submissions (14.1 MB)
*/
class Solution {
    func distanceBetweenBusStops(_ distance: [Int], _ start: Int, _ destination: Int) -> Int {
        var total: Int = 0;
        var subDistance: Int = 0;
        if start < destination {
            for (index, value) in distance.enumerated() {
                if index >= start && index < destination {
                    subDistance += value;
                }

                total += value;
            }
        } else {
            for (index, value) in distance.enumerated() {
                if index >= destination && index < start {
                    subDistance += value;
                }

                total += value;
            }

        }
        
        return (subDistance < total - subDistance) ? subDistance : total - subDistance;
    }
}
// @lc code=end
/*
[7,10,1,12,11,14,5,0]\n
7\n
2
*/
