/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-08-31
 * 151/151  (28 ms)
 * Your runtime beats 5.86 % of cpp submissions
 * Your memory usage beats 99.07 % of cpp submissions (14.7 M）
 */
static uint16_t s_map[1000];
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        uint16_t size = pushed.size();
        if (size < 3) {
            return true;
        }

        for (uint16_t i = 0; i < size; ++i) {
            s_map[pushed[i]] = i;
        }

        // pushed数组记录出栈时候的入栈顺序
        for (uint16_t i = 0; i < size; ++i) {
            pushed[i] = s_map[popped[i]];
        }

        // 不能允许有小于自己的顺序排列
        // ture条件：后出先入逆序
        int flagNum;
        for (uint16_t i = 0; i < size - 2; ++i) {
            flagNum = pushed[i];
            int fisrtNum = pushed[i + 1];
            for (uint16_t j = i + 2; j < size; ++j) {
                if (flagNum < pushed[j]) {
                    continue;
                }

                if (fisrtNum < pushed[j]) {
                    return false;
                } else {
                    fisrtNum = pushed[j];
                }
            }
        }

        return true;
    }
};
// @lc code=end
/*
[1,2,3,4,5]\n
[4,5,3,2,1]\n
[1,2,3,4,5]\n
[4,3,5,1,2]\n
[1,2]\n
[1,2]\n
[1,2,3]\n
[3, 2, 1]\n
[1,2,3]\n
[2, 3, 1]\n
[1,2,3]\n
[2, 1, 3]\n
[1,2,3]\n
[1, 3, 2]\n
[1,2,3]\n
[1, 2, 3]\n

[1,2,3,4]\n     
[1,2,3,4]\n     
[1,2,3,4]\n     
[1,2,4,3]\n     
[1,2,3,4]\n     
[1,3,2,4]\n     
[1,2,3,4]\n     
[1,3,4,2]\n     
[1,2,3,4]\n     
[1,4,2,3]\n     
[1,2,3,4]\n     
[1,4,3,2]\n     
[1,2,3,4]\n     
[2,1,3,4]\n     
[1,2,3,4]\n     
[2,1,4,3]\n     
[1,2,3,4]\n     
[2,3,1,4]\n     
[1,2,3,4]\n     
[2,3,4,1]\n     
[1,2,3,4]\n     
[2,4,1,3]\n     
[1,2,3,4]\n     
[2,4,3,1]\n     
[1,2,3,4]\n     
[3,1,2,4]\n     
[1,2,3,4]\n     
[3,1,4,2]\n     
[1,2,3,4]\n     
[3,2,1,4]\n     
[1,2,3,4]\n     
[3,2,4,1]\n     
[1,2,3,4]\n     
[3,4,1,2]\n     
[1,2,3,4]\n     
[3,4,2,1]\n     
[1,2,3,4]\n     
[4,1,2,3]\n     
[1,2,3,4]\n     
[4,1,3,2]\n     
[1,2,3,4]\n     
[4,2,1,3]\n     
[1,2,3,4]\n     
[4,2,3,1]\n     
[1,2,3,4]\n     
[4,3,1,2]\n     
[1,2,3,4]\n     
[4,3,2,1]\n     
*/

