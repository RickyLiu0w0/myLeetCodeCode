/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-10-08
    67/67 (148 ms)
    Your runtime beats 44.39 % of cpp submissions
    Your memory usage beats 24.88 % of cpp submissions (65.5 MB)
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, less<pair<int, size_t>>> pQ;
        size_t n = nums1.size();
        for (size_t i = 0; i < n; ++i) {
            pQ.push(make_pair(nums2[i], i));
        }

        size_t left = 0, right = n - 1;
        vector<int> res(n);
        while(!pQ.empty()) {
            pair<int, size_t> node = pQ.top();
            // cout << node.first << " " << node.second << endl;
            if (nums1[right] > node.first) {
                res[node.second] = nums1[right--];
            } else {
                res[node.second] = nums1[left++];
            }
            pQ.pop();
        }
        return res;
    }
};
// @lc code=end
/*
[2,7,11,15]\n
[1,10,4,11]\n
[12,24,8,32]\n
[13,25,32,11]\n
[1,2,9]\n
[2,3,5]\n
[9,1,2,4,5]\n
[6,2,9,1,4]\n
[15448,14234,13574,19893,6475]\n
[14234,6475,19893,15448,13574]
*/