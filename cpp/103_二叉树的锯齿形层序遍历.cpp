/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-25
 * 33/33 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 90.13 % of cpp submissions (11.7 MB)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> childNode;
        childNode.push(root);
        int currentCount = 1, nextCount = 0;
        bool reverse = false;
        while (!childNode.empty()) {
            vector<int> nodes;
            while(currentCount--) {
                TreeNode* node = childNode.front();
                childNode.pop();
                nodes.emplace_back(node->val);
                if (node->left) {
                    nextCount++;
                    childNode.push(node->left);
                }
                if (node->right) {
                    nextCount++;
                    childNode.push(node->right);
                }
            }
            if (reverse) {
                std::reverse(nodes.begin(), nodes.end());
                reverse = false;
            } else {
                reverse = true;
            }
            res.emplace_back(nodes);
            currentCount = nextCount;
            nextCount = 0;
        }
        return res;
    }
};
// @lc code=end

