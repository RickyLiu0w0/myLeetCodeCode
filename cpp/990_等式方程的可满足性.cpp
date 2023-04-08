/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-08
 * 181/181 (4 ms)
 * Your runtime beats 83.63 % of cpp submissions
 * Your memory usage beats 49.61 % of cpp submissions (11 MB)
 */
// 并差集题目
class UF {
public:
    explicit UF(int n) : parent_(n) {
        int i = 0;
        for (auto& x : parent_) {
            x = i++;
        }
    }

    int find(int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }

        return parent_[x];
    }

    void connect(int p, int q) {
        int root_p = find(p);
        int root_q = find(q);

        if (root_p == root_q) {
            // 相同子树
            return;
        }

        parent_[root_p] = root_q;
        return;
    }

    bool if_set(int p, int q) { return find(p) == find(q); }

private:
    vector<int> parent_;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);

        for (auto& s : equations) {
            if (s[1] == '=') {
                uf.connect(s[0] - 'a', s[3] - 'a');
            }
        }

        for (auto& s : equations) {
            if (s[1] == '!') {
                if (uf.if_set(s[0] - 'a', s[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
