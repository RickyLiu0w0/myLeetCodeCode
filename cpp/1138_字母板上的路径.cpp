/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

#include "AllInclude.h"

/**
 * Accepted 2023-02-12
 * 61/61 (4 ms)
 * Your runtime beats 31.31 % of cpp submissions
 * Your memory usage beats 30.3 % of cpp submissions (6 MB)
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        map<char, pair<int, int>> hash_map;

        // 录入地图信息
        int i = 0, j = 0;
        for (char c = 'a'; c <= 'z'; c += 1) {
            hash_map[c] = make_pair(i, j++);

            if (j == 5) {
                j = 0;
                ++i;
            }
        }

        i = j = 0;  // 当前位置
        string res = "";

        for (auto c : target) {
            pair<int, int> pos = hash_map[c];

            int row = pos.first - i;   // 纵向偏差
            int col = pos.second - j;  // 横向偏差

            if ('z' == c) {
                if (col > 0) {
                    // 目标在当前位置右边
                    res += string(col, 'R');
                } else {
                    // 目标在当前位置左边
                    res += string(-col, 'L');
                }

                if (row > 0) {
                    // 目标在当前位置下面
                    res += string(row, 'D');
                } else {
                    // 目标在当前位置上面
                    res += string(-row, 'U');
                }
            } else {
                if (row > 0) {
                    // 目标在当前位置下面
                    res += string(row, 'D');
                } else {
                    // 目标在当前位置上面
                    res += string(-row, 'U');
                }

                if (col > 0) {
                    // 目标在当前位置右边
                    res += string(col, 'R');
                } else {
                    // 目标在当前位置左边
                    res += string(-col, 'L');
                }
            }

            // 到达目标位置
            res.push_back('!');
            i = pos.first;
            j = pos.second;
        }
        return res;
    }
};
// @lc code=end
/*
"zdz"
*/
