/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */
#include "AllInclude.h"

// @lc code=start
/**
 * Accepted
 * 37/37(52 ms)
 * Your runtime beats 98.35 % of cpp submissions
 * Your memory usage beats 66.04 % of cpp submissions (31.4 MB)
 * 
 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiffer = INT_MAX;
        int arrSize = arr.size();
        vector<vector<int>> res;

        for (int i = 0; i < arrSize - 1; i++) {
            if (minDiffer > arr[i+1] - arr[i]) {
                // 更小的绝对差
                minDiffer =  arr[i+1] - arr[i];
                res.clear();
                res.push_back(vector<int>{arr[i], arr[i+1]});
            } else if (minDiffer == arr[i+1] - arr[i]) {
                res.push_back(vector<int>{arr[i], arr[i+1]});
            }
        }
        
        return res;
    }
};
// @lc code=end

