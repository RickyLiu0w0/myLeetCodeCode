/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // 当成是一个满二叉树进行运算
        queue<TreeNode*> nodeQueue;
        root->val = 1;
        nodeQueue.push(root);
        int maxWidth = 1, start, end;
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();

                if (0 == i) {
                    // 最左边的节点，记录编号
                    start = currentNode->val;
                }

                if (levelSize - 1 == i) {
                    // 最右边的节点，记录编号
                    end = currentNode->val;
                }

                if (currentNode->left) {
                    // 有左节点
                    currentNode->left->val = currentNode->val * 2;
                    nodeQueue.push(currentNode->left);
                }

                if (currentNode->right) {
                    // 有右节点
                    currentNode->right->val = currentNode->val * 2 + 1;
                    nodeQueue.push(currentNode->right);
                }
            }

            int width = end - start + 1;

            maxWidth = maxWidth < width ? width : maxWidth;
        }

        return maxWidth;
    }
};
// @lc code=end

/*
[0]\n
[1,3,2,5,3,null,9]\n
[1,3,2,5,null,null,9,6,null,7]\n
[1,3,2,5]\n
[0,0,0,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null]
*/
