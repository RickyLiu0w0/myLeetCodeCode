/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (53.65%)
 * Likes:    2590
 * Dislikes: 0
 * Total Accepted:    550K
 * Total Submissions: 1M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7]
 * 是数组 [0,3,1,6,2,2,7] 的子序列。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 *
 *
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-22
 * 54/54 (8 ms)
 * Your runtime beats 92.62 % of cpp submissions
 * Your memory usage beats 98.31 % of cpp submissions (10 MB)
*/
class Solution {
public:
    /*
    int lengthOfLIS(vector<int>& nums) {
        // 先找到局部最低点
        uint16_t i = 0, numsSize = nums.size();
        for (; i < numsSize - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }

        uint16_t localMinIndex = i, j, maxCount = 0;
        int* dp = (int*)calloc(numsSize, sizeof(int));
        for (; i < numsSize; ++i) {
            maxCount = 0;
            for (j = localMinIndex; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    maxCount = maxCount < dp[j] ? dp[j] : maxCount;
                }
            }
            dp[i] = maxCount + 1;
        }

        for(i = localMinIndex; i < numsSize; ++i) {
            maxCount = maxCount < dp[i] ? dp[i] : maxCount;
        }

        return maxCount;
    }*/

    int lengthOfLIS(vector<int>& nums) {
        // g[i] 表示长度i+1的LTS的末尾元素最小值
        /**
         * nums = [1,6,7,2,4,5,3]
         * g = [0,0,0,0,0,0,0]
         * g = [1,0,0,0,0,0,0] 1
         * g = [1,6,0,0,0,0,0] 6
         * g = [1,6,7,0,0,0,0] 7
         * g = [1,2,7,0,0,0,0] 2
         * g = [1,2,4,0,0,0,0] 4
         * g = [1,2,4,5,0,0,0] 5
         * g = [1,2,3,5,0,0,0] 3
         *
         */

        int ng = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto pos = lower_bound(nums.begin(), nums.begin() + ng, nums[i]);
            if (pos == ng + nums.begin()) {
                // 找不到，直接加入末尾
                nums[ng] = nums[i];
                ng++;
            } else {
                // 找到，换成最小值
                *pos = nums[i];
            }
        }
        return ng;
    }
};
// @lc code=end

/*
[10,9,2,5,3,7,101,18]\n
[0,1,0,3,2,3]\n
[7,7,7,7,7,7,7]\n
[2,1,3,7,101,18]\n
[2,2,2,1,3,2,5,4,6,1,7,1,9]\n
[1,3,6,7,9,4,10,5,6]
*/
