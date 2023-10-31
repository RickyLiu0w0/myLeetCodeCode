/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-08
 * 18/18 (576 ms)
 * Your runtime beats 5.36 % of cpp submissions
 * Your memory usage beats 5.35 % of cpp submissions (165.3 MB)
*/
class StockPrice {
    // 一个包含重复元素的有序集合，一个map
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if (time_to_price.count(timestamp)) {
            se.erase(se.find(time_to_price[timestamp]));
        }
        time_to_price[timestamp] = price;
        se.insert(price);
    }
    
    int current() {
        return (*time_to_price.rbegin()).second;
    }
    
    int maximum() {
        return *se.rbegin();
    }
    
    int minimum() {
        return *se.begin();
    }
private:
    multiset<int> se;
    map<int, int> time_to_price;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

/*
["StockPrice","update","update","current","maximum","update","maximum","update","minimum"]\n
[[],[1,10],[2,5],[],[],[1,3],[],[4,2],[]]\n
["StockPrice","update","maximum","current","minimum","maximum","maximum","maximum","minimum","minimum","maximum","update","maximum","minimum","update","maximum","minimum","current","maximum","update","minimum","maximum","update","maximum","maximum","current","update","current","minimum","update","update","minimum","minimum","update","current","update","maximum","update","minimum"]\n
[[],[38,2308],[],[],[],[],[],[],[],[],[],[47,7876],[],[],[58,1866],[],[],[],[],[43,121],[],[],[40,5339],[],[],[],[32,5339],[],[],[43,6414],[49,9369],[],[],[36,3192],[],[48,1006],[],[53,8013],[]]\n
*/