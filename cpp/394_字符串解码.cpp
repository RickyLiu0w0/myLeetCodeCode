/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-12
 * 34/34 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 17.21 % of cpp submissions (6.9 MB)
*/
class Solution {
public:
    string decodeString(string s) {
        stack<string> dq;
        int n = s.size();
        string temp_alpha = "";
        string temp_num = "";
        for (auto c : s) {
            if (isalpha(c)) {
                temp_alpha.push_back(c);
            } else if (isdigit(c)) {
                temp_num.push_back(c);
            } else if (c == '[') {
                dq.push(temp_alpha);
                temp_alpha.clear();
                dq.push(temp_num);
                temp_num.clear();
                dq.push("[");
            } else {
                // c == ']'
                // temp中的内容是需要使用数字重复的
                while (!dq.empty() && dq.top() != "[") {
                    temp_alpha = dq.top() + temp_alpha;
                    dq.pop();
                }
                if (dq.empty()) {
                    // 已经处理完所有括号
                    return temp_alpha;
                }
                dq.pop();  // 弹出 [
                int count = stoi(dq.top());  // 弹出数字
                dq.pop();
                string tmp;
                while (count--) {
                    tmp += temp_alpha;
                }
                dq.push(tmp);
                temp_alpha.clear();
            }
        }
        while (!dq.empty()) {
            temp_alpha = dq.top() + temp_alpha;
            dq.pop();
        }
        return temp_alpha;
    }
};
// @lc code=end

/*
"a"\n
"2[a]"\n
"a2[b]"\n
"a2[b]10[c]"\n
"3[a2[c]]"\n
"3[a]2[bc]"\n
"2[abc]3[cd]ef"\n
"abc3[cd]xyz"
*/