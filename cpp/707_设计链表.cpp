/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-09-23
    64/64 (36 ms)
    Your runtime beats 84.34 % of cpp submissions
    Your memory usage beats 86.01 % of cpp submissions (19 MB)
*/
struct MyLinkedListNode {
    int val_;
    MyLinkedListNode* next_;

    MyLinkedListNode(int val) {
        val_ = val;
        next_ = nullptr;
    }

    MyLinkedListNode(int val, MyLinkedListNode* next) {
        val_ = val;
        next_ = next;
    }
};

class MyLinkedList {
public:
    MyLinkedList() {
        this->head_ = nullptr;
        this->length_ = 0;
    }

    int get(int index) {
        MyLinkedListNode* node = this->head_;
        if (this->length_ <= index) {
            return -1;
        }

        for (uint16_t i = 0; i < index; ++i) {
            
            node = node->next_;
        }

        return node->val_;
    }

    void addAtHead(int val) {
        if (this->length_ == 0) {
            this->head_ = new MyLinkedListNode(val);
        } else {
            this->head_ = new MyLinkedListNode(val, this->head_);
        }
        ++this->length_;
    }

    void addAtTail(int val) {
        if (this->length_ == 0) {
            this->addAtHead(val);
            return;
        }

        MyLinkedListNode* node = this->head_;
        for (uint16_t i = 0; i < this->length_ - 1; ++i) {
            node = node->next_;
        }

        node->next_ = new MyLinkedListNode(val);
        ++this->length_;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) {
            this->addAtHead(val);
            return;
        }
        
        if (index == this->length_) {
            this->addAtTail(val);
            return;
        }

        if (index < this->length_) {
            MyLinkedListNode* node = this->head_;
            for (uint16_t i = 0; i < index - 1; ++i) {
                node = node->next_;
            }

            node->next_ = new MyLinkedListNode(val, node->next_);
            ++this->length_;
        }
    }

    void deleteAtIndex(int index) {
        if (index == 0) {
            this->head_ = this->head_->next_;
        } else if (index < this->length_) {
            MyLinkedListNode* node = this->head_;
            for (uint16_t i = 0; i < index - 1; ++i) {
                node = node->next_;
            }
            node->next_ = node->next_->next_;
        } else {
            return;
        }

        --this->length_;
    }

private:
    MyLinkedListNode* head_;
    uint16_t length_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
/*
["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]\n
[[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]\n
["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]\n
[[],[0,10],[0,20],[1,30],[0]]\n
["MyLinkedList","addAtTail","get"]\n
[[],[1],[0]]
*/