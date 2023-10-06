/*
 * @lc app=leetcode.cn id=2866 lang=cpp
 *
 * [2866] 美丽塔 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-26
 * 785/785 (220 ms)
 * Your runtime beats 27.1 % of cpp submissions
 * Your memory usage beats 42.23 % of cpp submissions (92.2 MB)
*/
#define ll long long
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        // 6 5 1 3 9 2 7 1
        // suf
        //               1
        //             7 1
        //           2 2 1 (7弹出)
        //         9 2 2 1
        //       3 3 2 2 1 (9弹出)
        //     1 1 1 1 1 1 (3, 2弹出)
        // 6 5 1 1 1 1 1 1  
        // suf[i]是i到最右边的最大和
        // pre[i]是0到i的最大和
        int n = maxHeights.size();
        vector<ll> suf(n + 1, 0);
        vector<ll> pre(n, 0);

        stack<int> st;
        st.push(n);  // 先把最右边的n压入，好计算i到n的个数
        ll sum = 0LL;
        for (ll i = n - 1; i > -1; --i) {
            while (st.size() > 1 && maxHeights[st.top()] >= maxHeights[i]) {
                // 要进入的数比栈顶的数小于等于，出栈
                ll j = st.top();
                st.pop();
                sum -= maxHeights[j] * (st.top() - j);
            }
            sum += maxHeights[i] * (st.top() - i);
            st.push(i);
            suf[i] = sum;
        }

        st = stack<int>();

        sum = 0LL;
        st.push(-1);
        for (ll i = 0; i < n; ++i) {
            while (st.size() > 1 && maxHeights[st.top()] >= maxHeights[i]) {
                ll j = st.top();
                st.pop();
                sum -= maxHeights[j] * (j - st.top()); // maxHeights[j]这个数所代表的区间
            }
            sum += maxHeights[i] * (i - st.top());
            st.push(i);
            pre[i] = sum;
        }

        ll res = suf[0];  // 全部递减
        for (int i = 0; i < n; ++i) {
            res = max(res, pre[i] + suf[i + 1]);
        }
        return res;
    }
};
// @lc code=end
