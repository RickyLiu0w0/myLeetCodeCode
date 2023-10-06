/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-26
 * 31/31 (20 ms)
 * Your runtime beats 81.11 % of cpp submissions
 * Your memory usage beats 17.63 % of cpp submissions (16.2 MB)
*/
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        // 保持栈顶最小
        if (!min_st.empty() && val > min_st.top()) {
            return;
        }
        min_st.push(val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if (!min_st.empty() && val == min_st.top()) {
            min_st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
private:
    stack<int> st;
    stack<int> min_st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

