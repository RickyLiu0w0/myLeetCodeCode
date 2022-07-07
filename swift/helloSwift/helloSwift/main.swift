//
//  main.swift
//  helloSwift
//
//  Created by Rickyliu on 2022/7/2.
//

import Foundation

print("Hello, World!")

var temp: Square! = Square(sideLength: 2, name: "temp");

print(temp.simpleDescription());

func foo(_ a:inout Int, B b: inout Int) {
    a+=1;
    b+=1;
}

var a = 3;
var b = 2;

//foo(&a, B: &b);

print("a/b = \(a/b)")

class Solution {
    func minCostToMoveChips(_ position: [Int]) -> Int {
        var oddCount : Int = 0;
        var evenCount : Int = 0;
        
        for chip in position {
            if (0 == chip % 2) {
                // 偶数
                evenCount += 1;
            } else {
                oddCount += 1;
            }
        }
        
        return oddCount > evenCount ? oddCount : evenCount;
    }
}
