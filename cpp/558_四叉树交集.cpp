/*
 * @lc app=leetcode.cn id=558 lang=cpp
 *
 * [558] 四叉树交集
 */

#include "AllInclude.h"

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
         Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/**
 * Accepted 2022-07-15 00:12
 * 61/61 (24 ms)
 * Your runtime beats 29.3 % of cpp submissions
 * Your memory usage beats 21.66 % of cpp submissions (15.8 MB)
 */

// @lc code=start
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node* res = new Node();

        // 处理递归终止条件
        if (quadTree1->isLeaf) {
            return quadTree1->val ? quadTree1 : quadTree2;
        }

        if (quadTree2->isLeaf) {
            return quadTree2->val ? quadTree2 : quadTree1;
        }

        res->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        res->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        res->bottomLeft =
            intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        res->bottomRight =
            intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        // 合并矩阵
        if (res->topLeft->isLeaf && res->topRight->isLeaf &&
            res->bottomLeft->isLeaf && res->bottomRight->isLeaf &&
            res->topLeft->val == res->topRight->val &&
            res->bottomLeft->val == res->topRight->val &&
            res->bottomLeft->val == res->bottomRight->val) {
            res->isLeaf = true;
            res->val = res->topLeft->val;
            res->topLeft = res->topRight = res->bottomLeft = res->bottomRight =
                NULL;
        }
        return res;
    }
};
// @lc code=end
/*
[[0,1],[1,1],[1,1],[1,0],[1,0]]\n
[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]\n
[[1,0]]\n
[[1,0]]\n
[[0,0],[1,1],[1,0],[1,1],[1,1]]\n
[[0,0],[1,1],[0,1],[1,1],[1,1],null,null,null,null,[1,1],[1,0],[1,0],[1,1]]\n
[[0,1],[1,0],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]\n
[[0,1],[0,1],[1,0],[1,1],[1,0],[1,0],[1,0],[1,1],[1,1]]\n
[[0,0],[1,0],[1,0],[1,1],[1,1]]\n
[[0,0],[1,1],[1,1],[1,0],[1,1]]
*/