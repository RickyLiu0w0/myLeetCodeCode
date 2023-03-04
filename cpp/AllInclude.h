#ifndef ALLINCLUDE_H
#define ALLINCLUDE_H

#include <algorithm>  // sort
#include <array>
#include <bitset>   // STL 位集容器
#include <climits>  // INT_MIN
#include <cmath>
#include <complex>  // 复数类
#include <cstring>  // memset(a, 0, sizeof(a)); memcpy(b, a, 4*sizeof(int));
#include <deque>
#include <forward_list>  // 单链表
#include <functional>    // lambda递归
#include <iostream>
#include <iterator>  // template <<
#include <list>      // STL 线性列表容器,双向链表
#include <map>       // 自动升序
#include <numeric>   // accumulate
#include <queue>
#include <set>            // 自动升序
#include <stack>          // 无迭代器
#include <string>         // 字符串类
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <vector>
using namespace std;

const int null_node = 1853189228;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ~ListNode() {
        if (next) {
            delete next;
        }
        cout << "Delete " << val << " node.\n";
    }
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        if (left) {
            delete left;
        }

        if (right) {
            delete right;
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    // out << '[';   // vector< vector<T> >
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    // out << "]";
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& v) {
    // out << '[';   // vector< vector<T> >
    if (!v.empty()) {
        out << '(';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b)";
    }
    // out << "]";
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<vector<T> >& vv) {
    out << "[\n";  // vector< vector<T> >
    if (!vv.empty()) {
        for (auto v : vv) {
            out << "  [";
            std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
            out << "\b\b],\n";
        }
        out << "\b\b";
    }
    out << "]";
    return out;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& v) {
    out << "{";
    for (auto& item : v) {
        out << item.first << ": " << item.second << ", ";
    }
    out << "\b\b}";
    return out;
}

ostream& operator<<(ostream& os, ListNode* lp) {
    ListNode* cur = lp;
    while (cur != nullptr) {
        os << cur->val << " -> ";
        cur = cur->next;
    }
    os << "null";
    return os;
}

ostream& operator<<(ostream& os, TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    os << "[";

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur) {
            os << cur->val << ", ";
            if (cur->left == cur->right && cur->left == nullptr) {
                continue;
            }
            q.push(cur->left);
            q.push(cur->right);
        } else {
            os << "null, ";
        }
    }

    os << "\b\b]";
    return os;
}

TreeNode* construct_binary_tree(vector<int>& vec, int len, int i) {
    if (vec.empty() || len < 1)
        return nullptr;
    TreeNode* root = nullptr;
    if (i < len && vec[i] != null_node) {
        root = new TreeNode(0);
        if (root == nullptr)
            return nullptr;
        root->val = vec[i];
        root->left = construct_binary_tree(vec, len, 2 * i + 1);
        root->right = construct_binary_tree(vec, len, 2 * i + 2);
    }
    return root;
}

#endif