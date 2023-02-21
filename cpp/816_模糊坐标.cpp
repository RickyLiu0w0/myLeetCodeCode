/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-11-07
 * 346/346 (8 ms)
 * Your runtime beats 65.94 % of cpp submissions
 * Your memory usage beats 92.03 % of cpp submissions (8.8 MB)
 */
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        size_t size = s.length() - 1;
        vector<string> res;

        for (size_t commas = 2; commas < size; ++commas) {
            for (size_t l = 2; l <= commas; ++l) {
                if (!check(s, l, 1, commas)) {
                    continue;
                }
                for (size_t r = commas + 1; r <= size; ++r) {
                    if (check(s, r, commas, size)) {
                        // 可以在r处插入dot
                        string s_sub = s;
                        if (r != size) {
                            s_sub.insert(r, ".");
                        }

                        s_sub.insert(commas, ", ");

                        if (l != commas) {
                            s_sub.insert(l, ".");
                        }

                        res.emplace_back(s_sub);
                    }
                }
            }
        }
        return res;
    }

private:
    bool check(const string& str, size_t pos, size_t begin, size_t end) {
        if (begin != pos - 1 && str[begin] == '0') 
            return false;

        return pos == end || str[end - 1] != '0';
    }
};
// @lc code=end
/*
"(1234)"\n
"(0123)"\n
"(100)"\n
"(00011)"\n
"(0100)"\n
"(010)"\n
"(01)"
*/