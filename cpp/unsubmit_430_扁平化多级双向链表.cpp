/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

#include "AllInclude.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        function<Node*(Node*)> dfs = [&](Node* ptr) -> Node* {
            Node* pre;
            while (ptr) {
                pre = ptr;
                Node* nxt = ptr->next;
                if (ptr->child) {
                    Node* ret = dfs(ptr->child);
                    ptr->next = ptr->child;
                    ptr->child->prev = ptr;
                    ptr->child = nullptr;
                    ret->next = nxt;
                    if (nxt) {
                        nxt->prev = ret;
                    }
                }
                ptr = ptr->next;
            }
            return pre;
        };
        if (head) {
            dfs(head);
        } else {
            return nullptr;
        }
        return head;
    }
};
// @lc code=end

