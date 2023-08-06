/*
 * @lc app=leetcode.cn id=722 lang=cpp
 *
 * [722] 删除注释
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-03
 * 54/54 (8 ms)
 * Your runtime beats 13.95 % of cpp submissions
 * Your memory usage beats 70.54 % of cpp submissions (7.5 MB)
*/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string ss = "";
        int status = 0;
        for (auto& s : source) {
            size_t n = s.length();
            for (size_t i = 0; i < n; ++i) {
                char c = s[i];
                if (c == '/') {
                    if (status == 0) {                       
                        if (i + 1 < n && s[i+1] == '*') {
                            // /*
                            ++i;
                            status = 1;
                        } else if (i + 1 < n && s[i+1] == '/') {
                            //遇到 //
                            break;
                        } else {
                            ss.push_back(c);
                        }
                    }
                } else if (c == '*') {
                    if (status == 1) {
                        if (i + 1 < n && s[i+1] == '/') {
                            // /*
                            ++i;
                            status = 0;
                        }
                    } else {
                        ss.push_back(c);
                    }
                } else {
                    if (status == 0) {
                        ss.push_back(c);
                    }
                }
            }
            if (status == 0 && !ss.empty()) {
                res.emplace_back(ss);
                ss.clear();
            }
        }

        return res;
    }
};
// @lc code=end

