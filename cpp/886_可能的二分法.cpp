/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-16
 * 70/70 (224 ms)
 * Your runtime beats 15.54 % of cpp submissions
 * Your memory usage beats 36.51 % of cpp submissions (69.2 MB)
*/
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        this->color_.fill(-1);
        for (auto dislike : dislikes) {
            // 整理好不能和编号i在一起的其他编号，无重复
            this->dislike_[dislike[0]].emplace_back(dislike[1]);
            this->dislike_[dislike[1]].emplace_back(dislike[0]);
        }

        for (int i = 1; i <= n; ++i) {
            if (-1 == this->color_[i]) {
                // 还没被填色，说明完全无关，随便填
                if (!setColorDfs(i, 1)) {
                    // 填不了了
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool setColorDfs(int id, int8_t color) {
        this->color_[id] = color;  // 填上色
        // 处理与他有关的值
        for (auto num : this->dislike_[id]) {
            int8_t numColor = this->color_[num];
            if (-1 == numColor) {
                // 还没填，填相反色
                if (!setColorDfs(num, color ^ 0b1)) {
                    // 填不了
                    return false;
                }
            } else if(numColor == color){
                // 仇人同一坑
                return false;
            }
        }
        return true;
    }

    array<vector<int>, 2001> dislike_;
    array<int8_t, 2001> color_;
};
// @lc code=end
/*
4\n
[[1,2],[1,3],[2,4]]\n
3\n
[[1,2],[1,3],[2,3]]\n
5\n
[[1,2],[2,3],[3,4],[4,5],[1,5]]\n
5\n
[]
*/