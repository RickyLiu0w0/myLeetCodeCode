/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:

    Solution():index_(0) {}

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        dataBase_[index_++] = longUrl;
        return to_string(index_);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dataBase_[atoi(shortUrl.c_str()) - 1];
    }
private:
    int index_;
    unordered_map<int, string> dataBase_;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

