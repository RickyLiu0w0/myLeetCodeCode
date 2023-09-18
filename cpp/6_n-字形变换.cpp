/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-12
 * 1157/1157 (32 ms)
 * Your runtime beats 25.69 % of cpp submissions
 * Your memory usage beats 18.16 % of cpp submissions (20.7 MB)
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (1 == numRows || s.length() <= numRows) {
            return s;
        }
        bool down = true;
        int x = 0, y = 0;
        vector<vector<char>> grid(numRows, vector<char>(s.length() - numRows + 1, ' '));
        string res;

        for (char c : s) {
            grid[x][y] = c;
            if (down) {
                // 探测是否到达底部
                if (x + 1 == numRows) {
                    x--;
                    y++;
                    down = false;
                } else {
                    x++;
                }
            } else {
                // 探测是否到达顶部
                if (x == 0) {
                    x++;
                    down = true;
                } else {
                    x--;
                    y++;
                }
            }
        }

        for (auto& row : grid) {
            for (auto c : row) {
                if (c != ' ') {
                    res.push_back(c);
                }
            }
        }

        return res;
    }
};
// @lc code=end

/*
"PAYPALISHIRING"\n1\n
"PAYPALISHIRING"\n2\n
"PAYPALISHIRING"\n3\n
"PAYPALISHIRING"\n4\n
"PAYPALISHIRING"\n5\n
"PAYPALISHIRING"\n6\n
"PAYPALISHIRING"\n7\n
"PAYPALISHIRING"\n8\n
"PAYPALISHIRING"\n13\n
"PAYPALISHIRING"\n14\n
"PAYPALISHIRING"\n1000\n
"A"\n1\n
*/