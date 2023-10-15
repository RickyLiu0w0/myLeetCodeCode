/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-10
 * 31/31 (8 ms)
 * Your runtime beats 94.62 % of cpp submissions
 * Your memory usage beats 16.58 % of cpp submissions (21.4 MB)
*/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* dfs(const vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return NULL;
        }

        int mid = begin + ((end - begin) >> 1);

        return new TreeNode(nums[mid], dfs(nums, begin, mid - 1), dfs(nums, mid + 1, end));
    }
};
// @lc code=end

