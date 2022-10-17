/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-09-07
 * 89/89 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 20.95 % of cpp submissions (6.2 MB)
 */
class Solution {
public:
    string reorderSpaces(string text) {
        uint16_t spaceCounter = 0;

        string word = "";
        vector<string> words;
        bool isFirstSpace = false;

        for (char c : text) {
            if (' ' == c) {
                ++spaceCounter;
                if (isFirstSpace) {
                    words.emplace_back(word);
                    word.clear();
                    isFirstSpace = false;
                }
            } else {
                word += c;
                isFirstSpace = true;
            }
        }

        if (!word.empty()) {
            words.emplace_back(word);
            word.clear();
        }

        uint16_t wordCounter = words.size();
        uint16_t reorderSpace = 0;
        uint16_t moreSpace = 0;

        if (wordCounter == 1) {
            moreSpace = spaceCounter;
        } else {
            reorderSpace = spaceCounter / (wordCounter - 1);
            moreSpace = spaceCounter % (wordCounter - 1);
        }

        for (uint16_t i = 0; i < wordCounter; ++i) {
            word += words[i];

            if (i < wordCounter - 1)
                word.append(reorderSpace, ' ');
            else
                word.append(moreSpace, ' ');
        }

        return word;
    }
};
// @lc code=end
/*
""  this   is  a sentence "\n
" practice   makes   perfect"\n
"hello   world"\n
"  walks  udp package   into  bar a"\n
"a"\n
"  a"\n
"a  "\n
" a ""
*/