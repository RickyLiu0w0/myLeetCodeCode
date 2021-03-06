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
    func arrayRankTransform(_ arr: [Int]) -> [Int] {
        let size = arr.count;
        if 0 == size {
            return [];
        }
        
        let arrSorted: [Int] = arr.sorted(by: {
            $0 < $1;
        });
        
        var counters: [Int: Int] = [arrSorted[0]:1];
        var counter: Int = 1;
        for index in 1..<size {
            if arrSorted[index - 1] == arrSorted[index] {
                // 两个相等，不统计
                continue;
            }
            
            counter += 1;
            counters[arrSorted[index]] = counter;
        }
        
        var res: [Int] = [];
        for num in arr {
            res.append(counters[num]!);
        }
        
        return res;
    }
}
