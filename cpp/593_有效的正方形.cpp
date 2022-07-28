/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        if (p1[0] == p2[0] && p1[1] == p2[1]) {
            return false;
        }

        return validSquareHelp(p1, p2, p3, p4) ||
               validSquareHelp(p1, p3, p2, p4) ||
               validSquareHelp(p1, p4, p2, p3);
    }

private:
    bool validSquareHelp(vector<int>& A, vector<int>& C, vector<int>& B,
                         vector<int>& D) {
        // 假设ac、bd线段是对角线，正方形的充要条件是对角线垂直且相等
        // 参考网站：https://blog.csdn.net/qq826309057/article/details/70942061

        const long AX = A[0];
        const long AY = A[1];
        const long CX = C[0];
        const long CY = C[1];

        const long BX = B[0];
        const long BY = B[1];
        const long DX = D[0];
        const long DY = D[1];

        // 1. 判断是否相交

        // 1.1 快速排斥实验
        // 点A点C横坐标的最大值不能小于点B点D横坐标的最小值
        // 点A点C纵坐标的最大值不能小于点B点D纵坐标的最小值
        // 点B点D横坐标的最大值不能小于点A点C横坐标的最小值
        // 点B点D纵坐标的最大值不能小于点A点C纵坐标的最小值
        if ((AX > CX ? AX : CX) < (BX < DX ? BX : DX) ||
            (AY > CY ? AY : CY) < (BY < DY ? BY : DY) ||
            (BX > DX ? BX : DX) < (AX < CX ? AX : CX) ||
            (BY > DY ? BY : DY) < (AY < CY ? AY : CY)) {
            return false;
        }

        // 1.2 跨立实验
        // AB X DB * CB X DB <= 0(点A、点C在BD的两侧或线段上)
        // BA X CA * DA X CA <= 0(点B、点D在CA的两侧或线段上)
        // AB == (AX - BX, AY - BY) DB == (DX - BX, DY - BY) CB == (CX - BX , CY - BY)
        // BA == (BX - AX, BY - AY) CA == (CX - AX, CY - AY) DA == (DX - AX , DY - AY)
        if ((((AX - BX) * (DY - BY) - (AY - BY) * (DX - BX)) *
             ((CX - BX) * (DY - BY) - (CY - BY) * (DX - BX))) > 0 ||
            (((BX - AX) * (CY - AY) - (BY - AY) * (CX - AX)) *
             ((DX - AX) * (CY - AY) - (DY - AY) * (CX - AX))) > 0) {
            return false;
        }

        // 2 判断是否垂直，向量AC，BD点积为0
        // AC * BD == 0
        if (((AX - CX) * (BX - DX)) + (((AY - CY) * (BY - DY)))) {
            return false;
        }

        // 3 判断是否相等
        // len(AC) == len(BD)
        return (AX - CX) * (AX - CX) + (AY - CY) * (AY - CY) ==
               (BX - DX) * (BX - DX) + (BY - DY) * (BY - DY);
    }
};
// @lc code=end
/*
[0,0]\n
[1,1]\n
[1,0]\n
[0,1]\n
[0,0]\n
[1,1]\n
[1,0]\n
[0,12]\n
[1,0]\n
[0,1]\n
[-1,0]\n
[0,-1]\n
[-7213,-701]\n
[-7214,-700]\n
[-7215,-701]\n
[-7214,-702]\n
[3,1]\n
[4,0]\n
[5,1]\n
[4,2]\n
[1134,-2539]\n
[492,-1255]\n
[-792,-1897]\n
[-150,-3181]\n
[0,0]\n
[0,0]\n
[0,0]\n
[0,0]\n
[2,1]\n
[1,2]\n
[0,0]\n
[2,0]
*/