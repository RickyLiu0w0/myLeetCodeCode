/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
 * Accepted 2022-09-05
 * 176/176 (40 ms)
 * Your runtime beats 43.36 % of cpp submissions
 * Your memory usage beats 87.04 % of cpp submissions (41.7 MB)
 */
class Solution {
    // 用字符串序列 "val(left)(right)"
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {set.begin(), set.end()};
    }

private:
    string dfs(TreeNode* node) {
        if (!node)
            return "";  // 空节点

        string serial = to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";

        if (unordered_map<string, TreeNode*>::iterator iter = map.find(serial); iter != map.end()) {
            // 已经存在过此路径
            set.insert(iter->second); 
        } else {
            map[serial] = node;
        }

        return serial;
    }

    unordered_map<string, TreeNode*> map;
    unordered_set<TreeNode*> set;
};
// @lc code=end
/*
[2,2,2,3,null,3,null]\n
[1,2,3,4,null,2,4,null,null,4]\n
[2,1,1]
*/