/*
 * @lc app=leetcode.cn id=2420 lang=cpp
 *
 * [2420] 找到所有好下标
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-09-27
    68/68 (116 ms)
    Your runtime beats 49.49 % of cpp submissions
    Your memory usage beats 98.45 % of cpp submissions (80.9 MB)
*/
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> res;
        uint32_t right = 1, left = 1;
        int size = nums.size();
        if (1 == k) {
            for(size_t i = 1; i < size - 1 ; ++i) {
                res.emplace_back(i);
            }
        } else {
            for(size_t i = 1; i < size - k - 1; ++i) {
                if (nums[i - 1] < nums[i]) {
                    // 出现递增，计数清1
                    left = 1;
                } else {
                    // 符合条件，计数加1
                    ++left;
                }

                if (nums[i + k] > nums[i + k + 1]) {
                    // 出现递减，计数清1
                    right = 1;
                } else {
                    // 符合条件，计数加1
                    ++right;
                }

                if (left >= k && right >= k) {
                    res.emplace_back(i + 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end

