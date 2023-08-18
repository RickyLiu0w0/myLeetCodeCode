/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-05-01
 * 39/39 (264 ms)
 * Your runtime beats 56.94 % of cpp submissions
 * Your memory usage beats 16.87 % of cpp submissions (140.6 MB)
*/
struct CompanyMember {
    int no_;
    int mss_arrive_time_;
    int mss_cost_time_;
    // CompanyMember* manager_;
    vector<CompanyMember*> subordinates_;
    CompanyMember() : mss_arrive_time_(0){}
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<CompanyMember*> company(n, nullptr);
        for (int i = 0; i < n; ++i) {
            CompanyMember* member = company[i];
            if (!member) {
                member = new CompanyMember();
                company[i] = member;
            }
            member->no_ = i;
            member->mss_cost_time_ = informTime[i];

            if (manager[i] != -1) {
                CompanyMember* _manger = company[manager[i]];
                if (!_manger) {
                    _manger = new CompanyMember();
                    company[manager[i]] = _manger;
                }
                _manger->subordinates_.emplace_back(member);
                // member->manager_ = _manger;
            }
        }

        int res = 0;
        function<void(CompanyMember*)> dfs = [&](CompanyMember* node) {
            if (node->mss_cost_time_ == 0) {
                return;
            }

            for (auto& subordinate : node->subordinates_){
                subordinate->mss_arrive_time_ = node->mss_arrive_time_ + node->mss_cost_time_;
                res = max(res, subordinate->mss_arrive_time_);
                dfs(subordinate);
            }
        };
        dfs(company[headID]);
        return res;
    }
};
// @lc code=end
