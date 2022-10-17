/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */
#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-09-03
 * 205/205 (196 ms)
 * Your runtime beats 46.85 % of cpp submissions
 * Your memory usage beats 36.3 % of cpp submissions (22.3 MB)
 */
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(
            pairs.begin(), pairs.end(),
            [](vector<int>& a, vector<int>& b) -> bool { return a[1] < b[1]; });

        int pairSize = pairs.size();
        int res = 0, end = INT_MIN;
        
        for(vector<int> pair : pairs) {
            if (end < pair[0]) {
                end = pair[1];
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
/*
[[1,2],[2,3],[3,4]]\n
[[3,4],[1,6],[2,6],[1,9],[5,19]]\n
[[-10,-8],[8,9],[-5,0],[6,10],[-6,-4],[1,7],[9,10],[-4,7]]
*/