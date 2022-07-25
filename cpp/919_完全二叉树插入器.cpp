/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/**
 * Accepted 2022-07-25 00:01
 * 84/84  (20 ms)
 * Your runtime beats 57.45 % of cpp submissions
 * Your memory usage beats 41.03 % of cpp submissions (22 MB) 
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> nodes;
        TreeNode* node;
        nodes.push(root);
        while (!nodes.empty()) {
            node = nodes.front();
            nodes.pop();
            if (node->left) {
                nodes.push(node->left);
            }

            if (node->right) {
                nodes.push(node->right);
            }

            this->tree.emplace_back(node);
        }
    }

    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        tree.emplace_back(node);
        // 寻找父节点
        TreeNode* parentNode = tree[(tree.size() / 2) - 1];
        if (parentNode->left) {
            // 左子节点已有
            parentNode->right = node;
        } else {
            parentNode->left = node;
        }
        return parentNode->val;
    }

    TreeNode* get_root() { return this->tree.front(); }

private:
    vector<TreeNode*> tree;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
