/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-17
 * 91/91 (76 ms)
 * Your runtime beats 98.06 % of cpp submissions
 * Your memory usage beats 96.08 % of cpp submissions (64.5 MB)
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int fruitA = -1, fruitB = -1, lastfruit = -1;
        int countA = 0, countB = 0, countA2 = 0, countB2 = 0;

        for (int fruit : fruits) {
            if (fruit == fruitA) {
                if (lastfruit != fruitA) {
                    countA2 += countA;
                    countA = 0;
                }
                ++countA;
            } else if (fruit == fruitB) {
                if (lastfruit != fruitB) {
                    countB2 += countB;
                    countB = 0;
                }
                ++countB;
            } else {
                res = res < (countA + countB + countA2 + countB2)
                          ? (countA + countB + countA2 + countB2)
                          : res;
                if (lastfruit == fruitB) {
                    countA = 1;
                    fruitA = fruit;
                } else {
                    countB = 1;
                    fruitB = fruit;  
                }
                countB2 = countA2 = 0;
            }
            lastfruit = fruit;
        }
        res = res < (countA + countB + countA2 + countB2)
                  ? (countA + countB + countA2 + countB2)
                  : res;
        return res;
    }
};
// @lc code=end
/*
[0]\n
[0,1]\n
[0,1,2]\n
[0,1,0]\n
[0,1,1]\n
[1,2,1]\n
[0,1,2,2]\n
[1,2,3,2,2]\n
[2,1,2,1,2,1,2,3,3,1,1,3,3,3]\n
[1,0,3,4,3]\n
[8,8,18,8,18,8,8,15,8,8,15,15,8,15,15,8,8,7,5]\n
[1,0,29,29,29,29,29,29,0,0,29,8,8,29,8,29,8,8,15,8,8,15,15,8,15,15,8,8,7,5]
*/