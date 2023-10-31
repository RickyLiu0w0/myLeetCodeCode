/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-29
 * 48/48 (152 ms)
 * Your runtime beats 79.75 % of cpp submissions
 * Your memory usage beats 34.52 % of cpp submissions (100.9 MB)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

/*
[73,74,75,71,69,72,76,73]\n
[30,40,50,60]\n
[30,60,90]\n
[31,31,31,31,31,31,32]\n
[31,31,31,31,31,31,31]\n
[35,34,33,32,31]
*/