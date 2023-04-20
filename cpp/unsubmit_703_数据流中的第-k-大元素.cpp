/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

#include "AllInclude.h"

// @lc code=start
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (auto& num : nums) {
            if (heap.size() != k) {
                heap.push(num);
            } else {
                if (num > heap.top()) {
                    heap.pop();
                    heap.push(num);
                }
            }
        }
    }

    int add(int val) {
        if (heap.size() != k_) {
            heap.push(val);
        } else if (val > heap.top()) {
            heap.push(val);
            heap.pop();
        }
        return heap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
