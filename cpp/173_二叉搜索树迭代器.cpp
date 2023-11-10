/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-10
 * 61/61 (24 ms)
 * Your runtime beats 81.78 % of cpp submissions
 * Your memory usage beats 26.76 % of cpp submissions (24 MB)
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        build(root);
    }
    
    int next() {
        int r = res.front();
        res.pop();
        return r;
    }
    
    bool hasNext() {
        return !res.empty();
    }
private:
    queue<int> res;
    void build(TreeNode* node) {
        if (!node) {
            return;
        }
        build(node->left);
        res.push(node->val);
        build(node->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

