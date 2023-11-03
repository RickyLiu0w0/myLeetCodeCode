/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

#include "AllInclude.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/**
 * Accepted 2023-11-03
 * 55/55 (12 ms)
 * Your runtime beats 74.87 % of cpp submissions
 * Your memory usage beats 21.19 % of cpp submissions (17.5 MB)
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return  NULL;
        }
        queue<Node*> q;
        q.push(root);
        int nxt = 0, cur = 1;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            --cur;
            if (node->left) {
                q.push(node->left);
                ++nxt;
            }
            if (node->right) {
                q.push(node->right);
                ++nxt;
            }
            if (cur) {
                node->next = q.front();
            } else {
                cur = nxt;
                nxt = 0;
            }
        }
        return root;
    }
};
// @lc code=end

