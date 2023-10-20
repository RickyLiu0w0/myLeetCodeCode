/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-18
 * 16/16 (40 ms)
 * Your runtime beats 98.79 % of cpp submissions
 * Your memory usage beats 33.57 % of cpp submissions (46 MB)
 */
struct Node {
    bool val;
    vector<Node*> children;
    Node() : val(false), children(26, nullptr) {}
};

class Trie {
public:
    Trie() { root = new Node; }

    void insert(string word) {
        Node* ptr = root;
        for (auto c : word) {
            if (ptr->children[c - 'a'] == nullptr) {
                ptr->children[c - 'a'] = new Node;
            }
            ptr = ptr->children[c - 'a'];
        }
        ptr->val = true;
    }

    bool search(string word) {
        Node* ptr = root;
        for (auto c : word) {
            if (ptr->children[c - 'a']) {
                ptr = ptr->children[c - 'a'];
            } else {
                return false;
            }
        }
        return ptr->val;
    }

    bool startsWith(string prefix) {
        Node* ptr = root;
        for (auto c : prefix) {
            if (ptr->children[c - 'a']) {
                ptr = ptr->children[c - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
