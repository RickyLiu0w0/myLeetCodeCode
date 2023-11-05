/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 *
 * [1488] 避免洪水泛滥
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-13
 * 82/82 (1696 ms)
 * Your runtime beats 5.71 % of cpp submissions
 * Your memory usage beats 88.57 % of cpp submissions (100.5 MB)
*/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> zero_index;
        unordered_map<int, int> rain_index;
        int n = rains.size();
        vector<int> res(n, 1024);
        for (int i = 0; i < n; ++i) {
            int num = rains[i];
            if (num) {
                if (rain_index.count(num)) {
                    int begin = rain_index[num];
                    auto pos = upper_bound(zero_index.begin(), zero_index.end(), begin);
                    if (pos != zero_index.end()) {
                        res[*pos] = num;
                        zero_index.erase(pos);
                    } else {
                        return {};
                    }
                }
                rain_index[num] = i;
                res[i] = -1;
            } else {
                zero_index.emplace_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

/*
[69,0,0,0,69]\n
[1,0,2,0,3,0,2,0,0,0,1,2,3]
*/