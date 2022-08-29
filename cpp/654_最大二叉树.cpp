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
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (1 == nums.size()) {
            return new TreeNode(nums[0]);
        }

        int maxNum = nums[0];
        vector<int>::iterator maxPos;
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
};
// @lc code=end
