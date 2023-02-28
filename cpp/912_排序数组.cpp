/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 冒泡排序
        // bubble_sort(nums);

        // 选择排序
        // select_sort(nums);

        // 插入排序
        insert_sort(nums);

        return nums;
    }

private:
    void bubble_sort(vector<int>& nums) {
        size_t n = nums.size();
        int temp;
        bool swap = false;
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                // j + i不会越界
                if (nums.at(j) > nums.at(j + 1)) {
                    // swap
                    temp = nums.at(j);
                    nums.at(j) = nums.at(j + 1);
                    nums.at(j + 1) = temp;
                    swap = true;
                }
            }
            if (!swap) {
                break;
            }
            return;
        }
    }

    void select_sort(vector<int>& nums) {
        size_t n = nums.size();
        for (int i = 0; i < n; ++i) {
            int min_index = i;
            for (int j = i; j < n; ++j) {
                if (nums.at(j) < nums.at(min_index)) {
                    min_index = j;
                }
            }
            int temp = nums[min_index];
            nums[min_index] = nums[i];
            nums[i] = temp;
        }
        return;
    }

    void insert_sort(vector<int>& nums) {
        size_t n = nums.size();
        for (int i = 1; i < n; ++i) {
            int val = nums.at(i);
            int j = i;
            while (j > 0 && val < nums.at(j - 1)) {
                nums[j] = nums[j - 1];
                --j;
            }
            nums.at(j) = val;
        }
    }
};
// @lc code=end

/*
[5,1,1,2,0,0]\n
[5,2,3,1]\n
[1,3,4,2,2,0,0]\n
[2,2,2,2,2,2,1]
*/