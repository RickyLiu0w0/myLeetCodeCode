/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-07-21
 * 30/30 (4 ms)
 * Your runtime beats 50.61 % of cpp submissions
 * Your memory usage beats 74.69 % of cpp submissions (8.5 MB)
 */

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
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool treeVal = false;
        return solution(root, treeVal);
    }

    TreeNode* solution(TreeNode* root, bool &treeVal) {
        bool temp = root->val;
        if (root->left) {
            if (solution(root->left, treeVal)) {
                temp |= (root->left->val | treeVal);
            } else {
                root->left = NULL;
            }
            // root->left = pruneTree(root->left);
        }

        if (root->right) {
            if (solution(root->right, treeVal)) {
                temp |= (root->right->val | treeVal);
            } else {
                root->right = NULL;
            }
            // root->right = pruneTree(root->right);
        }

        if (!temp) {
            return NULL;
        } else {
            treeVal = true;
            return root;
        }
    }
};
// @lc code=end
/*
[0,null,0,0,0]\n
[1,null,0,0,1]\n
[1,0,1,0,0,0,1]\n
[1,1,0,1,1,0,1,0]\n
[0,null,0,1,1,null,1,null,1,null,null,null,null]
*/