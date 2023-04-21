/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-12
 * 10/10 (28 ms)
 * Your runtime beats 89.37 % of cpp submissions
 * Your memory usage beats 57.4 % of cpp submissions (19.3 MB)
*/
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
