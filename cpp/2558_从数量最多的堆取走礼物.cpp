/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-28
 * 
 * 102/102 (8 ms)
 * Your runtime beats 63.57 % of cpp submissions
 * Your memory usage beats 20.93 % of cpp submissions (9.4 MB)
*/
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for_each(gifts.begin(), gifts.end(), [&pq](const int& gift){pq.push(gift);});
        long long res = 0LL;
        while (k--) {
            int tp = pq.top();
            pq.pop();
            pq.push(floor(sqrt(tp)));
        }
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

