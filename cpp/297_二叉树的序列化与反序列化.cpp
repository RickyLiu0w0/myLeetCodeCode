/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-21
 * 52/52 (56 ms)
 * Your runtime beats 29.72 % of cpp submissions
 * Your memory usage beats 14.44 % of cpp submissions (41.7 MB)
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "null";
        }

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> tree;
        string node;
        stringstream input(data);  // 读取str到字符串流中
        while (getline(input, node, ',')) {
            tree.push(node);
        }

        return deserialize_help(tree);
    }

    TreeNode* deserialize_help(queue<string>& tree) {
        string node = tree.front();
        tree.pop();

        if (node == "null") {
            return nullptr;
        }

        return node == "null" ? nullptr : new TreeNode(stoi(node), deserialize_help(tree), deserialize_help(tree));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
