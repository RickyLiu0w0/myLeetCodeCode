/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-18
 * 128/128 (100 ms)
 * Your runtime beats 5.2 % of cpp submissions
 * Your memory usage beats 45.76 % of cpp submissions (16.1 MB)
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
    int pathSum(TreeNode* root, int targetSum) {
        set<pair<TreeNode*, int>> memo;
        int res = 0;

        function<void(TreeNode*, long long)> dfs2 = [&](TreeNode* node, long long tar) {
            if (!node) {
                // printf("dfs(null, %d)\n", tar);
                return;
            }

            // 算上自己的
            // printf("dfs(%d, %d)\n", node->val, tar);
            if (tar - node->val == 0LL) {
                // cout << node->val << " ++res\n";
                res++;
            }
            dfs2(node->left, tar - node->val);
            dfs2(node->right, tar - node->val);
        };

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            // if (memo.count(make_pair(node, tar))) {
            //     return;
            // }
            // memo.insert(make_pair(node, tar));
            if (!node) {
                // printf("dfs(null, %d)\n", tar);
                return;
            }
            dfs2(node, targetSum);
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return res;
    }
};
// @lc code=end

/*
[10,5,-3,3]\n8\n
[10,5,-3,3,2,null,11]\n8\n
[10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
[0,5,-3,3,2,null,11,3,-2,null,1]\n8\n
[1,null,2,null,3,null,4,null,5]\n3\n
[1,null,2,null,3]\n3\n
[1,null,2]\n2
*/