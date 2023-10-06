/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-27
 * 53/53 (76 ms)
 * Your runtime beats 82.42 % of cpp submissions
 * Your memory usage beats 39.56 % of cpp submissions (27.8 MB)
*/
struct Filter {
    vector<pair<int, int>> after_filter;
    int veganFriendly_, maxPrice_, maxDistance_;

    vector<int> get_result() {
        sort(after_filter.begin(), after_filter.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });
        vector<int> res;
        for (auto& p : after_filter) {
            res.emplace_back(p.second);
        }
        return res;
    }

    void operator()(const vector<int>& restaurant) {
        if (veganFriendly_ && !restaurant[2]) {
            return;
        }
        if (restaurant[3] > maxPrice_ || restaurant[4] > maxDistance_) {
            return;
        }
        after_filter.emplace_back(restaurant[1], restaurant[0]);
    }

    Filter(int veganFriendly, int maxPrice, int maxDistance): veganFriendly_(veganFriendly), maxDistance_(maxDistance), maxPrice_(maxPrice){}
};

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        Filter filter(veganFriendly, maxPrice, maxDistance);
        return for_each(restaurants.begin(), restaurants.end(), filter).get_result();
    }
};
// @lc code=end

/*
[[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n0\n50\n10\n
[[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n1\n50\n10\n
[[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n0\n30\n3\n
*/