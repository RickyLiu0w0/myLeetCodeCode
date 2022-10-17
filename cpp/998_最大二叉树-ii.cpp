/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
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
 * Accepted 2022-08-30
 * 75/75 (8 ms)
 * Your runtime beats 29.02 % of cpp submissions
 * Your memory usage beats 81.96 % of cpp submissions (13 MB)
 */
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *currentNode = root, *preNode = nullptr;
        TreeNode* stack[100];
        int stackPrt = 0;
        stack[0] = root;

        while (1) {
            if (currentNode->val > val) {
                if (currentNode->right) {
                    preNode = currentNode;
                    currentNode = currentNode->right;
                    continue;
                } else {
                    currentNode->right = new TreeNode(val);
                    break;
                }
            }

            // currentNode->val < val
            if (preNode) {
                preNode->right = new TreeNode(val, preNode->right, nullptr);
            } else {
                root = new TreeNode(val, root, nullptr);
            }
            break;
        }

        return root;
    }
};
// @lc code=end
/*
[4,1,3,null,null,2]\n
5\n
[5,2,4,null,1]\n
3\n
[5,2,3,null,1]\n
4\n
[8,1,6,null,null,2,5]\n
4\n
[8,null,6,2,null,null,1]\n
4\n
[9,3,null,null,2]\n
1\n
[3]\n
2\n
[3]\n
5
*/
