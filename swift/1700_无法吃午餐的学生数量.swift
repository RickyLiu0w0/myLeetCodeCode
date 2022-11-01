/*
 * @lc app=leetcode.cn id=1700 lang=swift
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
/*
    Accepted 2022-10-19
    55/55 (0 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (13.7 MB)
*/
class Solution {
    func countStudents(_ students: [Int], _ sandwiches: [Int]) -> Int {
        let sandwichesSize: Int = sandwiches.count;
        var sandwichesIndex: Int = 0;

        let studentsSize: Int = students.count

        var flag = true;
        var students = students;
        var studentsIndex: Int = 0;

        while sandwichesIndex < sandwichesSize {
            if studentsIndex == studentsSize {
                if flag {
                    studentsIndex = 0;
                    flag = false;
                } else {
                    break;
                }
            }
            while studentsIndex < studentsSize {
                if students[studentsIndex] == sandwiches[sandwichesIndex] {
                    students[studentsIndex] = -1;
                    sandwichesIndex += 1;
                    studentsIndex += 1;
                    flag = true;
                    break;
                }
                studentsIndex += 1;
            }
        }

        var res: Int = 0;
        students.map {
            res += $0 == -1 ? 0 : 1;
        };
        
        return res;
    }
}
// @lc code=end
/*
[1,1,0,0]\n
[0,1,0,1]\n
[1,1,1,0,0,1]\n
[1,0,0,0,1,1]\n
[0,0,0]\n
[1,1,1]\n
[0,1,0]\n
[1,1,0]
*/
