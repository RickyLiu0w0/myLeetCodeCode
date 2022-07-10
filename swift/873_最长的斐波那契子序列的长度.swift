/*
 * @lc app=leetcode.cn id=873 lang=swift
 *
 * [873] 最长的斐波那契子序列的长度
 */

// @lc code=start
/*
Accepted 2022-07-09
56/56 (252 ms)
Your runtime beats 100 % of swift submissions
Your memory usage beats 100 % of swift submissions (14.2 MB)
*/
class Solution {
    func lenLongestFibSubseq(_ arr: [Int]) -> Int {
        // dp数组，存储键值对，key: 下一个需要依赖的值，value：依赖key的最长斐波拉契长度
        let arrSize: Int = arr.count;
        if arrSize == 3 {
            return arr[0] + arr[1] == arr[2] ? 3 : 0;
        }
        
        var dp_list: [[Int: Int]] = Array(repeating: [:], count: arrSize); // 前两个不用管
        var firstIndex: Int = 0;
        var secondIndex: Int = 0;
        var aa : Int = 2.0;
        
        for index: Int in 2..<arrSize {
            // 初始化
            firstIndex = 0;
            secondIndex = index - 1;
            
            while firstIndex < secondIndex {
                let sum: Int = arr[firstIndex] + arr[secondIndex];
                if sum == arr[index] {
                    dp_list[index].updateValue(3, forKey: arr[secondIndex]+arr[index]);
                    firstIndex += 1;
                    secondIndex -= 1;
                } else if sum < arr[index] {
                    // 需要把小的数字变大点（往后移）
                    firstIndex += 1;
                } else {
                    // 反之亦然
                    secondIndex -= 1;
                }
            }
        }
        
        for index in 3..<arrSize {
            for font in 2..<index {
                for (key, value) in dp_list[font] {
                    if key == arr[index] {
                        // 找到下一个斐波拉切数字
                        dp_list[index].updateValue(value + 1, forKey: arr[font]+key);
                        break;
                    }
                }
            }
        }
        
        var res: Int = 0;
        
        for index in 2..<arrSize {
            for (_, value) in dp_list[index] {
                res = value > res ? value : res;
            }
        }
        
        return res;
    }
}
// @lc code=end
/*
[1,2,3,4,5,6,7,8]\n
[1,3,7,11,12,14,18]
*/
