/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

#include "AllInclude.h"

// @lc code=start
template<typename V>
class TrieMap {
public:
    /***** 增/改 *****/

    // 在 Map 中添加 key
    void put(const string& key, V val);

    /***** 删 *****/

    // 删除键 key 以及对应的值
    void remove(const string& key);

    /***** 查 *****/

    // 搜索 key 对应的值，不存在则返回 null
    // get("the") -> 4
    // get("tha") -> null
    V get(const string& key) const;
    
    // 判断 key 是否存在在 Map 中
    // containsKey("tea") -> false
    // containsKey("team") -> true
    bool contains_key(const string& key) const;

    // 在 Map 的所有键中搜索 query 的最短前缀
    // shortest_prefix_of("themxyz") -> "the"
    string shortest_prefix_of(const string& query) const;

    // 在 Map 的所有键中搜索 query 的最长前缀
    // longest_prefix_of("themxyz") -> "them"
    string longest_prefix_of(const string& query) const;

    // 搜索所有前缀为 prefix 的键
    // keys_with_prefix("th") -> ["that", "the", "them"]
    vector<string> keys_with_prefix(const string& prefix) const;

    // 判断是和否存在前缀为 prefix 的键
    // has_key_with_prefix("tha") -> true
    // has_key_with_prefix("apple") -> false
    bool has_key_with_prefix(const string& prefix) const;

    // 通配符 . 匹配任意字符，搜索所有匹配的键
    // keys_with_pattern("t.a.") -> ["team", "that"]
    vector<string> keys_with_pattern(const String& pattern) const;

    // 通配符 . 匹配任意字符，判断是否存在匹配的键
    // hasKeyWithPattern(".ip") -> true
    // hasKeyWithPattern(".i") -> false
    bool has_key_with_pattern(const string& pattern) const;

    // 返回 Map 中键值对的数量
    int size() const;
private:
    const static int R = 256;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

    }
};
// @lc code=end

