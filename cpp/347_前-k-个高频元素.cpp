/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-29
 * 21/21 (16 ms)
 * Your runtime beats 50.29 % of cpp submissions
 * Your memory usage beats 23.72 % of cpp submissions (13.4 MB)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }
        /*
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
        for (auto& [k, v] : m) {
            q.emplace(v, k);
        }
        */
        vector<pair<int, int>> v;
        for (auto& [k, vv] : m) {
            v.emplace_back(vv, k);
        }

        // 快排核心函数
        auto adjust_array = [&v](int l, int r) -> int {
            auto x = v[l];
            while (l < r) {
                while (l < r && x.first <= v[r].first) {
                    --r;
                }
                v[l] = v[r]; // v[r]是右边第一个小于标志位的数

                while (l < r && x.first > v[l].first) {
                    ++l;
                }
                v[r] = v[l]; // v[l]是左边第一个大于等于标志位的数
            }
            v[l] = x; // 标志位左边都小于它，右边都大于等于它
            return l;
        };

        function<void(int,int)> quick_sort = [&](int begin, int end) {
            if (begin >= end) {
                return;
            }

            int index = adjust_array(begin, end);

            if (index == v.size() - k) {
                // 找到后k个
                return;
            }

            if (index > v.size() - k) {
                quick_sort(begin, index - 1); // 往左
            } else {
                quick_sort(index + 1, end); // 往右
            }
        };
        quick_sort(0, v.size() - 1);
        vector<int> res;
        while (k--) {
            res.emplace_back(v.back().second);
            v.pop_back();
        }
        return res;
    }
};
// @lc code=end
