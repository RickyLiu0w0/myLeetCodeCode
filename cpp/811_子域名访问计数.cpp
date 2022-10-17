/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-10-01
    52/52 (16 ms)
    Your runtime beats 47.12 % of cpp submissions
    Your memory usage beats 93.75 % of cpp submissions (11 MB)
*/
class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        map<string, int> resMap;
        for (string &s : cpdomains) {
            // size_t domainsCount = stoi(s.substr(0, s.find_first_of(' ')));
            uint16_t domainsCount = 0;
            uint8_t spacePos = 0;
            size_t size = s.length();
            for (char &c : s) {
                if (c == ' ') {
                    break;
                }

                domainsCount *= 10;
                domainsCount += c - '0';
                ++spacePos;
            }

            resMap[s.substr(spacePos + 1, size - spacePos)] += domainsCount;

            for(size_t i = size - 1; i > spacePos; --i) {
                if (s[i] == '.') {
                    resMap[s.substr(i + 1, size - i)] += domainsCount;
                }
            }
        }

        vector<string> res;
        for (auto item : resMap) {
            res.emplace_back(to_string(item.second) + " "+ item.first);
        }

        return res;
    }
};
// @lc code=end
