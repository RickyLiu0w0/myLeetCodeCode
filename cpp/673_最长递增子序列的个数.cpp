/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

#include "AllInclude.h"
// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        uint16_t i = 0, numsSize = nums.size();
        uint16_t j, maxCount = 0;

        // int* dp = (int*)calloc(numsSize, sizeof(int));
        uint16_t dp[numsSize];
        int pathCounts[numsSize];  // 基础是0

        for (; i < numsSize; ++i) {
            maxCount = 0;
            pathCounts[i] = 1;
            for (j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    // maxCount = maxCount < dp[j] ? dp[j] : maxCount;
                    if (maxCount < dp[j]) {
                        maxCount = dp[j];
                        pathCounts[i] = pathCounts[j];
                    } else if (maxCount == dp[j]) {
                        pathCounts[i] += pathCounts[j];
                    }
                }
            }
            dp[i] = maxCount + 1;
        }

        int ret = 0;
        maxCount = 0;
        for (i = 0; i < numsSize; ++i) {
            // maxCount = maxCount < dp[i] ? dp[i] : maxCount;
            if (maxCount < dp[i]) {
                maxCount = dp[i];
                ret = pathCounts[i];
            } else if (maxCount == dp[i]) {
                ret += pathCounts[i];
            }
        }

        return ret;
    }
};
// @lc code=end

/*
[1,3,5,4,7]\n
[1,3,5,4]\n
[2,2,2,2,2]\n
[10,9,2,5,3,7,101,18]\n
[0,1,0,3,2,3]\n
[7,7,7,7,7,7,7]\n
[2,1,3,7,101,18]\n
[2,2,2,1,3,2,5,4,6,1,7,1,9]\n
[1,3,6,7,9,4,10,5,6]
*/
