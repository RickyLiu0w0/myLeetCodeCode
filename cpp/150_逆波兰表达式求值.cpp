/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-27
 * 21/21 (16 ms)
 * Your runtime beats 24.6 % of cpp submissions
 * Your memory usage beats 11.15 % of cpp submissions (12.1 MB)
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& s : tokens) {
            if (s.size() == 1) {
                if (!isdigit(s[0])) {
                    // 是符号
                    int first = st.top();
                    st.pop();
                    int second = st.top();
                    st.pop();
                    switch (s[0]) {
                        case '+':
                            st.push(first + second);
                            break;
                        case '-':
                            st.push(second - first);
                            break;

                        case '*':
                            st.push(second * first);
                            break;
                        default:
                            st.push(second / first);
                            break;
                    }
                } else {
                    st.push(stoi(s));
                }
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
// @lc code=end

/*
["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
["4","13","5","/","+"]\n
["2","1","+","3","*"]
*/