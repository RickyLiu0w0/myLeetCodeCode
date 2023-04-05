/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-04
 * 83/83 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 5.35 % of cpp submissions (6.3 MB)
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s(version1);
        string buffer;
        vector<string> v1, v2;
        int v1_size = 0, v2_size = 0; // 最后两个要相等

        while (getline(s, buffer, '.')) {
            v1.emplace_back(buffer);
            v1_size++;
        }

        stringstream s2(version2);
        while (getline(s2, buffer, '.')) {
            v2.emplace_back(buffer);
            v2_size++;

            while (v1_size < v2_size) {
                v1.emplace_back("0");
                v1_size++;
            }
        }

        while (v2_size < v1_size) {
            v2.emplace_back("0");
            v2_size++;
        }


        for (int i = 0; i < v1_size; ++i) {
            if (stoi(v1[i]) > stoi(v2[i])) {
                return 1;
            } else if (stoi(v1[i]) < stoi(v2[i])) {
                return -1;
            }
        }
        return 0;
    }
};
// @lc code=end

