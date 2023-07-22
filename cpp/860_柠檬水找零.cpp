/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-22
 * 60/60 (80 ms)
 * Your runtime beats 76.59 % of cpp submissions
 * Your memory usage beats 90.69 % of cpp submissions (81.3 MB)
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (auto bill : bills) {
            switch (bill)
            {
            case 5:
                five++;
                break;
            case 10:
                if (five) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
                break;
            default:
                if (ten && five) {
                    ten--;
                    five--;
                } else if (!ten && five > 2) {
                    five -= 3;
                } else {
                    return false;
                }
                break;
            }
        }
        return true;
    }
};
// @lc code=end

