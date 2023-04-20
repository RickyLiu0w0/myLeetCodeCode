/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        struct cmp {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.first + a.second < b.first + b.second;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto num1 : nums1) {
            for (auto num2: nums2) {
                if (pq.size() == k) {
                    if (pq.top().first + pq.top().second > num1 + num2) {
                        pq.pop();
                        pq.push(make_pair(num1, num2));
                    }   
                } else {
                    pq.push(make_pair(num1, num2));
                }
            }
        }

        while (!pq.empty()) {
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
