/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-7-27
 * 216/216 (4 ms)
 * Your runtime beats 66.29 % of cpp submissions
 * Your memory usage beats 18.77 % of cpp submissions (11.9 MB)
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> nodes;
        int nextLevel = 0;
        int currentLevel = 1;
        nodes.push(root);
        vector<int> res;
        while (!nodes.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if (node->left) {
                nodes.push(node->left);
                nextLevel++;
            }

            if (node->right) {
                nodes.push(node->right);
                nextLevel++;
            }
            if (!(--currentLevel)) {
                // 这就是最右边的一个节点
                res.emplace_back(node->val);
                currentLevel = nextLevel;
                nextLevel = 0;
            }
        }
        return res;
    }
};
// @lc code=end

