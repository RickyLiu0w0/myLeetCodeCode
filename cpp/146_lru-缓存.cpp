/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

#include "AllInclude.h"

// @lc code=start

/**
 * Accepted 2023-02-28
 * 22/22 (420 ms)
 * Your runtime beats 27.92 % of cpp submissions
 * Your memory usage beats 25.03 % of cpp submissions (161.7 MB)
*/

// 实现双向链表+hash
struct Node {
    int val, key;
    Node *prev, *next;

    Node(int key, int val) {
        this->val = val;
        this->key = key;
    }
};

class DoubleList {
public:
    DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ~DoubleList() {
        Node* node = head->next;

        while (node != tail) {
            Node* delete_node = node;
            node = node->next;
            delete delete_node;
        }

        delete tail;
        delete head;
    }

    size_t get_size() const { return size; }

    void add_node(Node* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
        ++size;
        return;
    }

    // 删除某一节点，节点需要存在
    void remove_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size;
        return;
    }

    // 删除第一个节点，也就是最少用的
    Node* remove_first() {
        if (head->next == tail) {
            return nullptr;
        }

        Node* temp = head->next;
        remove_node(temp);
        return temp;
    }

private:
    size_t size;
    Node *head, *tail;  // 虚节点
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (m.end() == m.find(key)) {
            return -1;
        }

        make_recently_use(key);

        return m[key]->val;
    }

    void put(int key, int value) {
        if (m.end() != m.find(key)) {
            m[key]->val = value;
            make_recently_use(key);
            return;
        }

        if (double_list.get_size() >= capacity_) {
            move_last_recently_use();
        }

        add_recently_use(key, value);
    }

private:
    void make_recently_use(int key) {
        Node* node = m[key];
        double_list.remove_node(node);
        double_list.add_node(node);
    }

    void add_recently_use(int key, int val) {
        Node* node = new Node(key, val);
        double_list.add_node(node);
        m[key] = node;
    }

    void move_last_recently_use() {
        Node* node = double_list.remove_first();
        if (!node) {
            return;
        }
        m.erase(node->key);
        delete node;
    }

    DoubleList double_list;
    map<int, Node*> m;  // key, node
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
