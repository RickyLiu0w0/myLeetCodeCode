/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
 * Accepted 2022-07-31 15:12
 * 40/40(176 ms)
 * Your runtime beats 30.15 % of cpp submissions
 * Your memory usage beats 52.24 % of cpp submissions (104.7 MB)
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> levelNode;
        uint32_t level = 1, currentLevelCount = 1, nextLevelCount = 0;
        TreeNode* node;
        levelNode.push(root);
        int sum = 0, max_sum = INT_MIN, res;

        while (!levelNode.empty()) {
            node = levelNode.front();
            levelNode.pop();
            if (node->left) {
                levelNode.push(node->left);
                ++nextLevelCount;
            }

            if (node->right) {
                levelNode.push(node->right);
                ++nextLevelCount;
            }

            sum += node->val;

            if (!(--currentLevelCount)) {
                if (sum > max_sum) {
                    max_sum = sum;
                    res = level;
                }
                sum = 0;
                ++level;
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
            }
        }

        return res;
    }
};
// @lc code=end
/*
[989,null,10250,98693,-89388,null,null,null,-32127]
*/
