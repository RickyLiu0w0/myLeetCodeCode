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
        // insert_sort(nums);

        // 快速排序
        // quick_sort(nums, 0, nums.size() - 1);

        // 堆排序
        heap_sort(nums);

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

    void quick_sort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int pos = partiton(nums, left, right);
        quick_sort(nums, left, pos - 1);
        quick_sort(nums, pos + 1, right);
        return;
    }

    int partiton(vector<int>& nums, int left, int right) {
        int val = nums.at(left);
        while (left < right) {
            while (left < right && val <= nums.at(right)) {
                --right;
            }

            nums[left] = nums[right];  // 将比val小的放在左边

            while (left < right && val >= nums.at(left)) {
                ++left;
            }

            nums[right] = nums[left];  // 比val大的放右边
        }
        nums[left] = val;
        return left;
    }

    void heap_sort(vector<int>& nums) {
        size_t n = nums.size();
        nums.insert(nums.begin(), n);  // 加入虚拟头节点，习惯存储堆大小
        for (size_t i = n / 2; i > 0; --i) {
            max_heap(nums, i);
        }

        for (size_t i = 0; i < n; ++i) {
            pop_element(nums);
        }
        nums.erase(nums.begin());
        return;
    }

    void max_heap(vector<int>& nums, size_t i) {
        size_t n = nums.front();
        if (n < 2) {
            return;
        }
        int left_child = i << 1;
        int right_child = left_child + 1;
        int max_index = left_child;
        if (right_child <= n) {
            max_index = nums.at(left_child) < nums.at(right_child) ? right_child : left_child;
        }

        if (nums.at(i) < nums.at(max_index)) {
            int temp = nums.at(i);
            nums.at(i) = nums.at(max_index);
            nums.at(max_index) = temp;
            if (max_index > n / 2) {
                // 到叶子节点
                return;
            }
            max_heap(nums, max_index);
        }
        return;
    }

    void pop_element(vector<int>& nums) {
        size_t n = nums.front();
        int temp = nums.at(1);
        nums.at(1) = nums.at(n);
        nums.at(n) = temp;
        nums[0] = n - 1;
        max_heap(nums, 1);
        return;
    }
};
// @lc code=end

/*
[5,1,1,2,0,0]\n
[5,2,3,1]\n
[1,3,4,2,2,0,0]\n
[2,2,2,2,2,2,1]\n
[3,2,1,5,6,4]\n
[3,2,3,1,2,4,5,5,6]
*/