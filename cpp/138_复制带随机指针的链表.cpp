/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

#include "AllInclude.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start

// Definition for a Node.
/*
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/**
 * Accepted 2023-08-02
 * 19/19 cases passed (8 ms)
 * Your runtime beats 79.21 % of cpp submissions
 * Your memory usage beats 5.26 % of cpp submissions (15.6 MB)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }

        auto find_result = node_pair.find(head);
        if (find_result != node_pair.end()) {
            // 对应节点已经被创建
            return (*find_result).second;
        }

        Node* res = new Node(head->val);
        node_pair.insert(make_pair(head, res));

        res->random = copyRandomList(head->random);
        res->next = copyRandomList(head->next);


        return res;
    }

private:
    map<Node*, Node*> node_pair;
};
// @lc code=end
