/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-10
 * 21/21 cases passed (308 ms)
 * Your runtime beats 28.98 % of cpp submissions
 * Your memory usage beats 88.19 % of cpp submissions (114.1 MB)
*/
class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (small.size() >= large.size()) {
            small.push(num);
            large.push(small.top());
            small.pop();
        } else {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
        return;
    }
    
    double findMedian() {
        if (large.size() < small.size()) {
            return small.top();
        } else if (large.size() > small.size()) {
            return large.top();
        } else {
            return (large.top() + small.top()) / 2.0;
        }
    }
private:
    priority_queue<int> large;  // 最小值堆
    priority_queue<int, vector<int>, greater<int>> small; // 最大值堆

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

