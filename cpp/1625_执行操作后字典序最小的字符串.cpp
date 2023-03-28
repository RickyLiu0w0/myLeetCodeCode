/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-19
 * 80/80 cases passed (388 ms)
 * Your runtime beats 6 % of cpp submissions
 * Your memory usage beats 6 % of cpp submissions (122.9 MB) 
 */
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> se;
        queue<string> q;
        string res = s;
        int size = s.length();
        q.push(s);

        while (!q.empty()) {
            string ss = q.front();
            res = min(res, ss);

            string t1 = ss;
            for (int i = 1; i < size; i+=2){
                t1[i] = ((t1[i] - '0') + a < 10) ? (t1[i] + a) : (t1[i] + a - 10);
            }

            string t2 = ss.substr(size - b, b) + ss.substr(0, size - b);

            for (auto& t : {t1, t2}) {
                if (!se.count(t)) {
                    se.insert(t);
                    q.push(t);
                }
            }

            q.pop();

        }

        return res;
    }
};
// @lc code=end

