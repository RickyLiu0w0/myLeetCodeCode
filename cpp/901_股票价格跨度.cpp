/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-21
 * 99/99 (188 ms)
 * Your runtime beats 76.94 % of cpp submissions
 * Your memory usage beats 62.27 % of cpp submissions (82.2 MB)
 */
class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int count = 1;
        while (!s_.empty() && s_.top().first <= price) {
            count += s_.top().second;
            s_.pop();
        }
        s_.push(make_pair(price, count));
        return count;
    }
private:
    stack<pair<int, int>> s_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
/*
["StockSpanner","next","next","next","next","next","next","next"]\n
[[],[100],[80],[60],[70],[60],[75],[85]]\n
["StockSpanner","next","next","next","next","next","next","next"]\n
[[],[10],[80],[60],[60],[60],[75],[85]]\n
*/
