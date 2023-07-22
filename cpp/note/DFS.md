# DFS

https://labuladong.github.io/algo/di-san-zha-24031/bao-li-sou-96f79/yi-wen-mia-4f482/

模版：

```cpp

// 树
void traverse(TreeNode* root) {
    traverse(root->left);
    traverse(root->right);
}

// 二维矩阵
void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n) {
        return;
    }
    if (visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    dfs(grid, i - 1, j, visited); // 上
    dfs(grid, i + 1, j, visited); // 下
    dfs(grid, i, j - 1, visited); // 左
    dfs(grid, i, j + 1, visited); // 右
}

```

## 岛屿问题

### [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands/)

最简单的DFS题目

通过设置为水(`0`)代表已遍历过，遇到一座新的岛统计数+1，然后将其淹没

```cpp
class Solution {
public:
    // 这道题是最基础的DFS遍历，通过0标记为已遍历过 
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int length = grid.at(0).size();
        int width = grid.size();
        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x == width || y < 0 || y == length) {
                return;
            }

            if (grid[x][y] == '0') {
                return;
            }

            grid[x][y] = '0'; // 标记为被水淹没
            // 四个方向处理
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        };

        for (int i = 0; i < width; ++i) {
            for (size_t j = 0; j < length; ++j) {
                if (grid[i][j] == '1') {
                    // 淹没掉，统计数+1
                    ++res;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};
```