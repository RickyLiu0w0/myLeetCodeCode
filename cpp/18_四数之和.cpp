/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-7-15
 * 293/293 (124 ms)
 * Your runtime beats 8.9 % of cpp submissions
 * Your memory usage beats 5.06 % of cpp submissions (13.4 MB)
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = vector<vector<int>>();
        int end = nums.size() - 1, i = 0;
        while (i + 2 < end) {
            int num = nums[i];
            vector<vector<int>> threeSum = this->threeSum(nums, i + 1, end, target - num);
            for (vector<int>& it : threeSum) {
                it.push_back(nums[i]);
                res.push_back(it);
            }
            while (i + 2 < end && nums.at(i) == num) ++i;
        }
        return res;
    }

private:
    vector<vector<int>> twoSum(vector<int>& v, int begin, int end, long long tar) {
        vector<vector<int>> res = vector<vector<int>>();
        while (begin < end) {
            int left = v.at(begin), right = v.at(end);
            if (left + right < tar) {
                while (begin < end && v.at(begin) == left) ++begin;
            } else if (v.at(begin) + v.at(end) > tar) {
                while (begin < end && v[end] == right) --end;
            } else {
                res.push_back({v[begin++], v[end--]});
                while (begin < end && v.at(begin) == left) ++begin;
                while (begin < end && v[end] == right) --end;
            }
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& v, int begin, int end, long long tar) {
        vector<vector<int>> res = vector<vector<int>>();
        while (begin + 1 < end) {
            int num = v[begin];
            vector<vector<int>> twoSum = this->twoSum(v, begin + 1, end, tar - num);
            for (vector<int>& it : twoSum) {
                it.push_back(v[begin]);
                res.push_back(it);
            }
            while (begin + 1 < end && v.at(begin) == num) ++begin;
        }
        return res;
    }
};
// @lc code=end

/*
[1,0,-1,0,-2,2]\n0\n
[2,2,2,2,2]\n8\n
[1000000000,1000000000,1000000000,1000000000]\n-294967296
*/