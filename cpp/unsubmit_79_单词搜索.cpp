/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include "AllInclude.h"

// @lc code=start
const int direction_x[4] = {-1, 1, 0, 0};  // 上下左右
const int direction_y[4] = {0, 0, -1, 1};  // 上下左右

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        char entrance_char = word.front();
        int m = board.size(), n = board.front().size();

        // 寻找入口字符位置
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (entrance_char == board[i][j]) {
                    // 开始寻找路径
                    string path;
                    if (backtrack(board, word, path, 0, i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, string& target_word, string& path, const int target_index, const int i,
                   const int j) {
        if (i < 0 || j == board.front().size() || i == board.size() || j < 0 || target_index == target_word.length()) {
            // 超出边界
            return false;
        }

        char c = board[i][j];
        if (c != target_word[target_index]) {
            // 字符对不上
            return false;
        }

        path.push_back(board[i][j]);
        board[i][j] = '0';  // 标记已使用
        if (path == target_word) {
            // 找到字符
            return true;
        }

        // 选择列表，上下左右四个方向
        for (size_t k = 0; k < 4; ++k) {
            if (backtrack(board, target_word, path, target_index + 1, i + direction_x[k], j + direction_y[k])) {
                return true;
            }
        }

        // 撤销选择
        board[i][j] = path.back();
        path.pop_back();
        return false;
    }
};
// @lc code=end
