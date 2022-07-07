/*
 * @lc app=leetcode.cn id=729 lang=swift
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start

/*
    Accepted 2022-07-05 12:17
    107/107 (284 ms)
    Your runtime beats 65.63 % of swift submissions
    Your memory usage beats 43.75 % of swift submissions (14.5 M)
*/

class MyCalendar {
    init() {}
    
    func book(_ start: Int, _ end: Int) -> Bool {
        let size: Int = schedule.count;
        
        if(0 == size){
            schedule.append([start, end]);
            return true;
        }
        
        var l: Int = 0;
        var r: Int = size - 1;
        var mid: Int = (r - l) / 2 + l;
        
        if(end <= schedule[0][0]) {
            // 处理好边界条件，例如区间右端点都比最左端点小，直接放入开头
            schedule.insert([start, end], at: 0);
            return true
        } else if (start >= schedule[r][1]) {
            // 区间左端点都比最右端点大，直接放入结尾
            schedule.append([start, end]);
            return true;
        }
        
        while (l < r) {
            mid = (r - l) / 2 + l;
            if (start > schedule[mid][0]) {
                if (l == mid) {
                    // 当 l + 1 == r 的时候，l已满足要求
                    break;
                }
                l = mid;
            } else if (start < schedule[mid][0]) {
                r = mid;
            } else {
                // 开头就重合，直接退出
                return false;
            }
        }
        
        // l 的位置就是最靠近start且小于start的值
        if (schedule[l][1] > start) {
            return false;
        }
        
        // start合法性验证通过，接下来验证end
        if (schedule[l + 1][0] < end) {
            // end跨到别人区间去啦
            return false;
        } else {
            schedule.insert([start, end], at: l + 1);
            return true;
        }
    }

    var schedule: [[Int]] = [];
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * let obj = MyCalendar()
 * let ret_1: Bool = obj.book(start, end)
 */
// @lc code=end

/*
["MyCalendar", "book", "book"]\n
[[], [16, 18], [18,20]]\n
["MyCalendar","book","book","book"]\n
[[],[10,20],[15,25],[20,30]]\n
["MyCalendar","book","book","book","book", "book", "book"]\n
[[],[19,22],[0,20],[0,19],[17,23], [17, 19], [18, 19]]\n
["MyCalendar", "book", "book", "book"]\n
[[], [10, 20], [15, 25], [20, 30]]\n
["MyCalendar", "book", "book", "book", "book"]\n
[[], [10, 20], [5, 10], [20,25], [12, 16]]\n
["MyCalendar","book","book","book","book","book"]\n
[[],[37,50],[33,50],[4,17],[35,48],[8,25]]\n
["MyCalendar","book","book","book","book","book","book","book","book","book","book","book","book","book","book"]\n
[[],[23,32],[42,50],[6,14],[0,7],[21,30],[26,31],[46,50],[28,36],[0,6],[27,36],[6,11],[20,25],[32,37],[14,20]]\n
["MyCalendar","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book"]\n
[[],[23,32],[42,50],[6,14],[0,7],[21,30],[26,31],[46,50],[28,36],[0,6],[27,36],[6,11],[20,25],[32,37],[14,20],[7,16],[13,22],[39,47],[37,46],[42,50],[9,17],[49,50],[31,37],[43,49],[2,10],[3,12],[8,14],[14,21],[42,47],[43,49],[36,43]]
*/