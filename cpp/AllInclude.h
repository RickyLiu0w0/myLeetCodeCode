#ifndef ALLINCLUDE_H
#define ALLINCLUDE_H

#include <algorithm>  // sort
#include <bitset>     // STL 位集容器
#include <climits>    // INT_MIN
#include <cmath>
#include <complex>  // 复数类
#include <cstring>  // memset(a, 0, sizeof(a)); memcpy(b, a, 4*sizeof(int));
#include <deque>
#include <forward_list>  // 单链表
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    // out << '[';   // vector< vector<T> >
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
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
        out << ")";
    }
    // out << "]";
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<vector<T> >& vv) {
    out << '[';  // vector< vector<T> >
    if (!vv.empty()) {
        for (auto v : vv) {
            out << '[';
            std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
            out << "], ";
        }
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
    out << "}";
    return out;
}

#endif