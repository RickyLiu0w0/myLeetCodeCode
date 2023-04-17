/*
 * @lc app=leetcode.cn id=2409 lang=cpp
 *
 * [2409] 统计共同度过的日子数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-17
 * 51/51 (4 ms)
 * Your runtime beats 31.71 % of cpp submissions
 * Your memory usage beats 17.56 % of cpp submissions (5.9 MB)
*/
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrive_Alice_month = stoi(arriveAlice.substr(0, 2));
        int arrive_Alice_day = stoi(arriveAlice.substr(3, 2));

        int leave_Alice_month = stoi(leaveAlice.substr(0, 2));
        int leave_Alice_day = stoi(leaveAlice.substr(3, 2));

        int arrive_Bob_month = stoi(arriveBob.substr(0, 2));
        int arrive_Bob_day = stoi(arriveBob.substr(3, 2));

        int leave_Bob_month = stoi(leaveBob.substr(0, 2));
        int leave_Bob_day = stoi(leaveBob.substr(3, 2));

        // 找到最小时间区块
        int arrive_late_month, arrive_late_day, leave_early_month, leave_early_day;
        if (arrive_Alice_month < arrive_Bob_month) {
            // alice比bob早来
            arrive_late_month = arrive_Bob_month;
            arrive_late_day = arrive_Bob_day;
        } else if (arrive_Alice_month > arrive_Bob_month) {
            // bob比alice早来
            arrive_late_month = arrive_Alice_month;
            arrive_late_day = arrive_Alice_day;
        } else {
            // arrive_Alice_month == arrive_Bob_month
            arrive_late_month = arrive_Alice_month;
            arrive_late_day = max(arrive_Bob_day, arrive_Alice_day);
        }

        if (leave_Alice_month < leave_Bob_month) {
            // alice比bob早走
            leave_early_month = leave_Alice_month;
            leave_early_day = leave_Alice_day;
        } else if (leave_Alice_month > leave_Bob_month) {
            // bob比alice早走
            leave_early_month = leave_Bob_month;
            leave_early_day = leave_Bob_day;
        } else {
            // leave_Alice_month == leave_Bob_month
            leave_early_month = leave_Bob_month;
            leave_early_day = min(leave_Alice_day, leave_Bob_day);
        }

        if (leave_early_month < arrive_late_month ||
            (leave_early_month == arrive_late_month && leave_early_day < arrive_late_day)) {
            return 0;
        }

        int res = 0;
        const array<int, 13> month_day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // 处理日子
        if (leave_early_month == arrive_late_month) {
            return leave_early_day - arrive_late_day + 1;
        } else {
            res += leave_early_day + month_day[arrive_late_month++] - arrive_late_day + 1;
        }

        // 处理月份
        // leave_early_month >= arrive_late_month
        while (leave_early_month != arrive_late_month) {
            res += month_day[arrive_late_month++];
        }

        return res;
    }
};
// @lc code=end

/*
"09-01"\n"10-19"\n"06-19"\n"10-20"\n
"01-01"\n"12-31"\n"01-01"\n"12-30"\n
"08-15"\n"08-18"\n"08-16"\n"08-19"\n
"10-01"\n"10-31"\n"11-01"\n"12-31"\n
*/