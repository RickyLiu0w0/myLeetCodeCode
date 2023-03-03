/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-03
 * 33/33 (148 ms)
 * Your runtime beats 83.61 % of cpp submissions
 * Your memory usage beats 63.94 % of cpp submissions (64.2 MB)
*/
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> m;
        vector<string> res;

        for (auto& name : names) {
            if (1 == m.count(name)) {
                // 存在原本文件夹
                int counter = m[name];
                string new_name = name + "(";
                new_name.append(to_string(counter));
                new_name.append(")");
                
                // 加入结果
                while (1 == m.count(new_name)) {
                    ++counter;
                    new_name = name + "(";
                    new_name.append(to_string(counter));
                    new_name.append(")");
                }
                m[name] = counter + 1;
                m[new_name]++;
                res.emplace_back(new_name);
            } else {
                // 不存在
                res.emplace_back(name);  // 无需修改加入结果
                m[name]++;               // 统计数+1
            }
        }
        return res;
    }
};
// @lc code=end

/*
["pes","fifa","gta","pes(2019)"]\n
["gta","gta(1)","gta","avalon"]\n
["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]\n
["wano","wano","wano","wano"]\n
["kaido","kaido(1)","kaido","kaido(1)"]
*/
