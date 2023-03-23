/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-13
 * 111/111 (4 ms)
 * Your runtime beats 66.1 % of cpp submissions
 * Your memory usage beats 83.47 % of cpp submissions (10.8 MB)
*/
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        size_t n = energy.size();
        int res = 0;
        for (size_t i = 0; i < n; ++i) {
            initialEnergy -= energy.at(i);
            if (initialExperience <= experience.at(i)) {
                res += (experience.at(i) - initialExperience + 1);
                initialExperience = experience.at(i) * 2 + 1;
            } else {
                initialExperience += experience.at(i);
            }
        }
        if (initialEnergy <= 0) {
            res -= initialEnergy;
            ++res;
        }
        return res;
    }
};
// @lc code=end

/*
5\n3\n[1,4]\n[2,5]
*/