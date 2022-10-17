/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-13
 * 52/52 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 49.95 % of cpp submissions (7 MB)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, maxNum = 0;
        int size = arr.size();

        for (int index = 0; index < size; ++index) {
            maxNum = max(maxNum, arr[index]);
            if (index == maxNum) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
/*
[4,3,2,1,0]\n
[1,0,2,3,4]\n
[0,3,1,2,4]\n
[0,2,3,1,4]\n
[0]\n
[1,0]\n
[0,1]\n
[1,2,3,4,0]\n
[1,0,4,3,2]\n
[0,3,2,5,6,9,8,7,4,1]\n
[1,4,0,2,3,5]
*/
