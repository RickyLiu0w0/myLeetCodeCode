/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_t i = 0;
        
        if (!preorder.size()) {
            return nullptr;
        }

        for (auto& node : inorder) {
            val_to_index[node] = i;
            ++i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, size_t> val_to_index;

    TreeNode* build(vector<int>& preorderm, size_t pre_start, size_t pre_end, vector<int>& inorder, size_t in_strat,
                    size_t in_end) {
        if (pre_start > pre_end) {
            return nullptr;
        }

        int root_val = preorderm[pre_start];
        size_t in_index = val_to_index[root_val];
        size_t left_size = in_index - in_strat;

        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorderm, pre_start + 1, pre_start + left_size, inorder, in_strat, in_index - 1);
        root->right = build(preorderm, pre_start + left_size + 1, pre_end, inorder, in_index + 1, in_end);

        return root;
    }
};
// @lc code=end
