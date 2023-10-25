/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 *
 * [1402] 做菜顺序
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-22
 * 60/60 (36 ms)
 * Your runtime beats 5.41 % of cpp submissions
 * Your memory usage beats 13.06 % of cpp submissions (8.4 MB)
*/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size(), res = 0;
        
        function<int(int,int)> dfs = [&](int index, int pos) -> int {
            if (index < 0 || pos < 0) {
                return 0;
            }

            return dfs(index - 1, pos - 1) + pos * satisfaction[index];
        };
        for (int i = 0; i <= n; ++i) {
            res = max(res, dfs(n - 1, i));
        }
        return res;
    }
};
// @lc code=end

/*
[4,3,2]\n
[-1,-8,0,5,-9]\n
[-1,-4,-5]
*/