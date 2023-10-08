/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-07
 * 19/19 (244 ms)
 * Your runtime beats 27.68 % of cpp submissions
 * Your memory usage beats 72.61 % of cpp submissions (94.7 MB)
*/
class RandomizedSet {
public:
    RandomizedSet() {
        this->size_ = 0;
    }
    
    bool insert(int val) {
        if (ma.count(val)) {
            return false;
        }

        if (size_ == v.size()) {
            v.emplace_back(val);
        } else {
            v[size_] = val;
        }

        ma[val] = size_++;
        return true;
    }
    
    bool remove(int val) {
        if (!ma.count(val)) {
            return false;
        }

        // 删除
        int index = ma[val];
        ma.erase(val);

        // 最后一个数不用移动
        if (size_ - 1 == index) {
            --size_;
            return true;
        }

        // 将最后一个数字放入被删除的空格内
        int last = v[size_ - 1];
        v[index] = last;
        ma[last] = index;

        --size_;

        return true;
    }
    
    int getRandom() {
        return v[rand() % size_];  //范围[min,max)]
    }
private:
    vector<int> v;
    unordered_map<int, int> ma; // <num, index>
    int size_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

/*
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]\n
[[], [1], [2], [2], [], [1], [2], []]\n
["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]\n
[[],[0],[0],[0],[],[0],[0]]\n
*/