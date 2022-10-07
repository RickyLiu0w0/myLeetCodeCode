/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-09-12
    111/111 (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 49.12 % of cpp submissions (5.8 MB)
*/
class Solution {
public:
    int maximumSwap(int num) {
        string numS = to_string(num);
        uint8_t sizeNum = numS.length();
        vector<pair<uint8_t, uint8_t>> vec;
        for (uint8_t i = 0; i < sizeNum; ++i) {
            vec.emplace_back(pair<uint8_t, uint8_t>(numS[i], i));
        }

        sort(vec.begin(), vec.end(),
             [=](pair<uint8_t, uint8_t> &a, pair<uint8_t, uint8_t> &b) -> bool {
                 return a.first > b.first;
             });

        for (uint8_t i = 0; i < sizeNum; ++i) {
            if (vec[i].first != numS[i]) {
                // 找到最大值可以放的地方
                uint8_t j = i;
                while (j + 1 != sizeNum && vec[j].first == vec[j + 1].first) {
                    // 后面还有相同的值
                    ++j;
                }
                char temp = numS[i];
                numS[i] = vec[j].first;
                numS[vec[j].second] = temp;
                break;
            }
        }

        return stoi(numS);
    }
};
// @lc code=end
/*
2736\n
9973\n

4123\n
4132\n
4312\n
4321\n

1423\n
1432\n
3412\n
3421\n

1243\n
1342\n
3142\n
3241\n

1234\n
1324\n
3124\n
3214\n

19902032
*/
