/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        set<int> s_set;
        uint size = nums.size();
        uint16_t res = 0;
        for(uint16_t i = 0; i < size; ++i) {
            s_set.clear();
            int num = nums[i];
            while(s_set.end() == s_set.find(num)) {
                s_set.insert(num);
                num = nums[num];
            }

            res = res > s_set.size() ? res : s_set.size();
        }

        return res;
    }
};
// @lc code=end

