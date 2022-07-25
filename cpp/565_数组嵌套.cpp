/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepte 2022-07-17 11:20
 * 885/885 (560 ms)
 * Your runtime beats 5.16 % of cpp submissions
 * Your memory usage beats 11.47 % of cpp submissions (142.2 MB)
 */
class Solution {
public:
    // 暴力超时的，别试
    int arrayNesting(vector<int>& nums) {
        set<int> s_set;
        int size = nums.size();
        int res = 0;
        bool flag[size];
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < size; ++i) {
            // s_set.clear();
            int counter = 0;
            int num = nums[i];

            if(flag[num]) {
                continue;
            }

            while (s_set.end() == s_set.find(num)) {
                s_set.insert(num);
                ++counter;
                num = nums[num];
            }

            res = res > counter ? res : counter;
            flag[i] = true;
        }

        return res;
    }
};
// @lc code=end
