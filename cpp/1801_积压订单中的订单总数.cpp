/*
 * @lc app=leetcode.cn id=1801 lang=cpp
 *
 * [1801] 积压订单中的订单总数
 */

#include "AllInclude.h"

/**
 * Accepted 2023-01-02
 * 69/69 (188 ms)
 * Your runtime beats 87.63 % of cpp submissions
 * Your memory usage beats 27.84 % of cpp submissions (62.8 MB)
 */

// @lc code=start
#define MOD (1000000000 + 7)
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // 用两个字典存，price是key，amount是val
        map<int, uint32_t, greater<int>> buy_orders;  // 降序排列
        map<int, uint32_t, less<int>> sell_orders;    // 升序排列

        for (auto& order : orders) {
            uint32_t buy_amount;
            uint32_t sell_amount;

            if (order.at(2)) {
                // Sell
                sell_amount = order.at(1);
                while (1) {
                    auto buy_order = buy_orders.begin();
                    if (buy_orders.empty() || buy_order->first < order.at(0)) {
                        // buy最大的都还没有这单大，直接添加
                        sell_orders[order.at(0)] += sell_amount;
                        break;
                    } else {
                        buy_amount = buy_order->second;

                        if (buy_amount > sell_amount) {
                            // sell被消耗完，buy还有剩
                            buy_order->second -= sell_amount;
                            break;
                        } else if (buy_amount < sell_amount) {
                            // buy被消耗完，sell还有剩，继续消耗buy
                            sell_amount -= buy_amount;
                            buy_orders.erase(buy_order);
                        } else {
                            // sell被消耗完，buy被消耗完
                            buy_orders.erase(buy_order);
                            break;
                        }
                    }
                }
            } else {
                // Buy;
                buy_amount = order.at(1);
                while (1) {
                    auto sell_order = sell_orders.begin();
                    if (sell_orders.empty() || sell_order->first > order.at(0)) {
                        // sell最小的都买不起，直接添加
                        buy_orders[order.at(0)] += buy_amount;
                        break;
                    } else {
                        sell_amount = sell_order->second;

                        if (buy_amount < sell_amount) {
                            // buy被消耗完，sell还有剩
                            sell_order->second -= buy_amount;
                            break;
                        } else if (buy_amount > sell_amount) {
                            // sell被消耗完，buy还有剩，继续消耗buy
                            buy_amount -= sell_amount;
                            sell_orders.erase(sell_order);
                        } else {
                            // sell被消耗完，buy被消耗完
                            sell_orders.erase(sell_order);
                            break;
                        }
                    }
                }
            }
        }
        /*
        for (auto& order : buy_orders) {
            cout << "(" << order.first << ", " << order.second << ") ";
        }
        cout << endl;
        for (auto& order : sell_orders) {
            cout << "(" << order.first << ", " << order.second << ") ";
        }
        cout << endl;
        */

        int res = 0;
        for (auto& order : buy_orders) {
            res += order.second;
            res %= MOD;
        }
        for (auto& order : sell_orders) {
            res += order.second;
            res %= MOD;
        }
        return res;
    }
};
// @lc code=end
/*
[[10,5,0]]\n
[[10,5,0],[15,2,1],[25,1,1],[30,4,0]]\n
[[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]\n
[[944925198,885003661,0],[852263791,981056352,0],[16300530,415829909,0],[940927944,713835606,0],[606389372,407474168,1],[139563740,85382287,1],[700244880,901922025,1],[972900669,15506445,0],[576578542,65339074,0],[45972021,293765308,0],[464403992,97750995,0],[29659852,536508041,0],[799523481,299864737,0],[711908211,480514887,1],[354125407,677598767,1],[279004011,688916331,0],[263524013,64622178,0],[375395974,460070320,0],[971786816,379275200,1],[577774472,214070125,1],[987757349,711231195,0]]
*/