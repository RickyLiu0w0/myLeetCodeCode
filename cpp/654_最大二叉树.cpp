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
 */
class Solution {
public:
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