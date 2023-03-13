/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Accepted 2022-08-29
 * 107/107 (84 ms)
 * Your runtime beats 43.3 % of cpp submissions
 * Your memory usage beats 25.37 % of cpp submissions (48 MB)
 * 
 * Accepted 2023-03-13
 * 107/107 (60 ms)
 * Your runtime beats 99.16 % of cpp submissions
 * Your memory usage beats 74.14 % of cpp submissions (41.1 MB)
 */
class Solution {
public:
    /*
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (1 == nums.size()) {
            return new TreeNode(nums[0]);
        }

        int maxNum = nums[0];
        vector<int>::iterator maxPos = nums.begin();
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            if (*iter > maxNum) {
                maxNum = *iter;
                maxPos = iter;
            }
        }

        if (maxPos == nums.begin()) {
            nums.erase(nums.begin());
            return new TreeNode(maxNum, nullptr, constructMaximumBinaryTree(nums));
        } else if (maxPos + 1 == nums.end()) {
            nums.pop_back();
            return new TreeNode(maxNum, constructMaximumBinaryTree(nums), nullptr);
        }

        vector<int> left(nums.begin(), maxPos);

        nums.erase(nums.begin(), maxPos + 1);

        return new TreeNode(maxNum, constructMaximumBinaryTree(left), constructMaximumBinaryTree(nums));
    }
    */
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return this->build(nums, 0, nums.size() - 1);
    }

private:
    // 处理数组[io, hi]之前的树
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }

        // 找最大值
        size_t max_index = lo;
        for (size_t i = lo + 1; i <= hi; ++i) {
            if (nums[max_index] < nums[i]) {
                max_index = i;
            }
        }

        // 最大值就是根节点
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = build(nums, lo, max_index - 1);
        root->right = build(nums, max_index + 1, hi);
        return root;
    }
};
// @lc code=end
/*
[0]\n
[1,0]\n
[0,1]\n
[0,1,2,3]\n
[3,2,1,0]\n
[3,2,1,6,0,5]
*/