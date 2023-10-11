/*
 * @lc app=leetcode.cn id=2512 lang=cpp
 *
 * [2512] 奖励最顶尖的 K 名学生
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-11
 * 30/30 (512 ms)
 * Your runtime beats 11.11 % of cpp submissions
 * Your memory usage beats 52.94 % of cpp submissions (55.4 MB)
 */
struct Student {
    int id_;
    int score_;
    Student(int id) : id_(id), score_(0) {}
};

bool cmp(const Student& a, const Student& b) {
    if (a.score_ == b.score_) {
        return a.id_ < b.id_;
    }
    return a.score_ > b.score_;
}

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id, int k) {
        set<string> positive_feedback_set(positive_feedback.begin(), positive_feedback.end());
        set<string> negative_feedback_set(negative_feedback.begin(), negative_feedback.end());
        priority_queue<Student, vector<Student>, decltype(&cmp)> q(cmp);
        int n = report.size();
        for (int i = 0; i < n; ++i) {
            Student st(student_id[i]);
            string s;
            stringstream ss(report[i]);
            while (getline(ss, s, ' ')) {
                if (positive_feedback_set.count(s)) {
                    st.score_ += 3;
                } else if (negative_feedback_set.count(s)) {
                    st.score_--;
                }
            }
            q.push(st);
            if (q.size() == k + 1) {
                q.pop();
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.emplace_back(q.top().id_);
            // cout << q.top().id_ << " " << q.top().score_<< endl;
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

/*
["smart","brilliant","studious"]\n["not"]\n["this student is studious","the student is smart"]\n[1,2]\n2\n
["smart","brilliant","studious"]\n["not"]\n["this student is not studious","the student is smart"]\n[1,2]\n2
*/