/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-07-07 12:00
 * 126/126 (72 ms)
 * Your runtime beats 29.76 % of cpp submissions
 * Your memory usage beats 95.39 % of cpp submissions (22.8 MB)
 */
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> dictionary_set(dictionary.begin(), dictionary.end());
        string res, buff, temp;
        uint8_t buffSize, j;
        for (char c : sentence) {
            if (' ' != c) {
                buff += c;
            } else {
                temp = "";
                buffSize = buff.length();
                for (j = 0; j < buffSize; ++j) {
                    temp += buff[j];
                    if (dictionary_set.end() != dictionary_set.find(temp)) {
                        // 找到前缀
                        break;
                    }
                }

                res += ((j == buffSize) ? buff : temp) + ' ';
                buff = "";
            }
        }

        // 处理最后的单词
        temp = "";
        buffSize = buff.length();
        for (j = 0; j < buffSize; ++j) {
            temp += buff[j];
            if (dictionary_set.end() != dictionary_set.find(temp)) {
                // 找到前缀
                break;
            }
        }

        res += (j == buffSize) ? buff : temp;

        return res;
    }
};
// @lc code=end
/*
["cat","bat","rat"]\n
"the cattle was rattled by the batter"\n
["a","b","c"]\n
"aadsfasf absbs bbab cadsfafs"
*/