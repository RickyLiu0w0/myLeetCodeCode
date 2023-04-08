/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

#include "AllInclude.h"

// @lc code=start
/**
 * 2023-06-07 美团面试
 * Accepted 2023-06-08
 * 146/146 (4 ms)
 * Your runtime beats 54.82 % of cpp submissions
 * Your memory usage beats 78.87 % of cpp submissions (6.4 MB)
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();

        if (n < 4 || n > 16) {
            return {};
        }
        vector<string> res;
        // begin起始下标，block_index，第几块
        function<void(int begin, int block_index)> dfs = [&](int begin, int block_index) {
            // 结束条件
            if (s.size() <= begin) {
                return;
            }

            if (block_index == 3) {
                // 最后一块
                if (s.size() - begin > 3) {
                    // 最后一块长度大于3，不合法分割，或者啥东西都不剩了
                    return;
                }

                if (stoi(s.substr(begin)) <= 255) {
                    if (s.size() - begin > 1 && s[begin] == '0') {
                        // 出现前导0
                        return;
                    }

                    // cout << "1: " << s.substr(begin) << endl;
                    // xxx.xxx.xxx.0 ~ xxx.xxx.xxx.255
                    // cout << "res " << s << endl;
                    res.emplace_back(s);
                }
                return;
            }

            // 选择列表，当前block内可以选0～255，但是不能前导0

            // 一个位 .0. ~ .9.
            // 确保.之后的不是0
            // cout << "2: " << s[begin] << endl;
            s.insert(begin + 1, ".");
            dfs(begin + 2, block_index + 1);
            s.erase(begin + 1, 1);  // 撤销选择

            // 两个到三个位 .10. ~ .255.
            // 不能有前导0
            if (s[begin] != '0') {
                for (int i = 2; i <= 3 && begin + i < s.size(); ++i) {
                    // 确保不大于255
                    // cout << "2: " << s.substr(begin, i) << endl;
                    if (stoi(s.substr(begin, i)) > 255) {
                        continue;
                    }
                    
                    s.insert(begin + i, ".");
                    dfs(begin + 1 + i, block_index + 1);
                    s.erase(begin + i, 1);  // 撤销选择
                }
            }

            return;
        };
        dfs(0, 0);
        return res;
    }
};
// @lc code=end

/*
"25525511135"\n
"0000"\n
"101023"\n
"1111"\n
"1"\n
"255255255255"\n
"999999999"\n
"99999999999999999999"
*/