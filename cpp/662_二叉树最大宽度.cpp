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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Accepted 2022-08-27
 * 114/114 (12 ms)
 * Your runtime beats 30.64 % of cpp submissions
 * Your memory usage beats 13.73 % of cpp submissions (17.3 MB)
 */

typedef pair<TreeNode*, uint32_t> NodePair;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<NodePair*> nodeQueue;
        nodeQueue.push(new NodePair(root, 1));
        int res = 1;

        while (!nodeQueue.empty()) {
            int nodeSize = nodeQueue.size();
            uint32_t start, end;

            for (int i = 0; i < nodeSize; ++i) {
                NodePair* currentPair = nodeQueue.front();
                nodeQueue.pop();
                TreeNode* currentNode = currentPair->first;
                uint32_t currentWeight = currentPair->second;

                if (0 == i) {
                    // 最左边节点
                    start = currentWeight;
                }

                if (nodeSize == i + 1) {
                    // 最右边节点
                    end = currentWeight;
                }

                if (currentNode->left) {
                    nodeQueue.push(new NodePair(currentNode->left, currentWeight * 2));
                }

                if (currentNode->right) {
                    nodeQueue.push(new NodePair(currentNode->right, currentWeight * 2 + 1));
                }
            }

            int width = end - start + 1;
            res = res < width ? width : res;
        }
        return res;
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
