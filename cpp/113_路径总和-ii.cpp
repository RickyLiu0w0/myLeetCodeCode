/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-03
 * 115/115 (16 ms)
 * Your runtime beats 24.46 % of cpp submissions
 * Your memory usage beats 66.63 % of cpp submissions (19.3 MB)
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return vector<vector<int>>{};
        }
        vector<int> path{root->val};
        trackback(root, targetSum, path);
        return res;
    }
private: 
    vector<vector<int>> res;
    void trackback(TreeNode* root, int targetSum, vector<int>& path) {
        if (root->left == root->right && !root->left) {
            // 到达叶子节点
            if (root->val == targetSum) {
                res.emplace_back(path);
            }
        }

        // 选择列表，左右子树
        if (root->left) {
            path.emplace_back(root->left->val); // 作出选择
            trackback(root->left, targetSum - root->val, path);
            path.pop_back(); // 撤销选择
        }

        if (root->right) {
            path.emplace_back(root->right->val); // 作出选择
            trackback(root->right, targetSum - root->val, path);
            path.pop_back(); // 撤销选择
        }
        return;
    }
};
// @lc code=end

/*
[1]\n1\n
[1,2]\n1\n
[1,2]\n3\n
[1,0]\n1\n
[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
[5,4,8,11,null,13,4,7,2,null,null,null,1]\n23\n
[1,2,3]\n5\n
[]\n1
*/