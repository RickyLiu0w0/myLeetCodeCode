/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
 * Accepted 2023-09-06
 * 81/81 (4 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 86.67 % of cpp submissions (20.5 MB)
*/
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lca(root, 0).first;
    }

private:
    pair<TreeNode*, int> lca(TreeNode* node, int level) {
        if (!node) {
            return make_pair(nullptr, 0);
        }
        pair<TreeNode*, int> left = lca(node->left, level + 1);
        pair<TreeNode*, int> right = lca(node->right, level + 1);
        if (left.first == right.first && !left.first) {
            return make_pair(node, level);
        }

        if (!left.first || !right.first) {
            // 有一边空的
            return left.first ? left : right;
        }

        // 左右不为空
        if (left.second == right.second) {
            return make_pair(node, left.second);  // 记录下最大深度
        }

        return left.second > right.second ? left : right;
    }
};
// @lc code=end

/*
[3,5,1,6,2,0,8,null,null,7,4]\n
[1]\n
[0,1,3,null,2]
*/