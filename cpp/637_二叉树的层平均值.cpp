/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

#include "AllInclude.h"

/**
 * Accepted 2022-06-30 17:00
 * 66/66 (16 ms)
 * Your runtime beats 42.7 % of cpp submissions
 * Your memory usage beats 98.44 % of cpp submissions (21.7 MB)
 **/

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> treeQ;
        TreeNode* node;
        vector<double> res;
        int nextLevelCount = 0, currentLevelCount = 1, nodeCount = 0;
        long sum = 0;
        treeQ.push(root);

        while (!treeQ.empty()) {
            node = treeQ.front();
            ++nodeCount;
            sum += node->val;
            treeQ.pop();
            if (node->left) {
                treeQ.push(node->left);
                ++nextLevelCount;
            }

            if (node->right) {
                treeQ.push(node->right);
                ++nextLevelCount;
            }

            if (nodeCount == currentLevelCount) {
                res.push_back((double)sum / nodeCount);
                currentLevelCount = nextLevelCount;
                nextLevelCount = nodeCount = sum = 0;
            }
        }

        return res;
    }
};
// @lc code=end

/*
[3,9,20,15,7]\n
[3,9,20,null,null,15,7]\n
[2147483647,2147483647,2147483647]
*/