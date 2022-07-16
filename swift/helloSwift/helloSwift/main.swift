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

class MovingAverage {

    /** Initialize your data structure here. */
    init(_ size: Int) {
        array = Array(repeating: 0, count: size);
        self.size = size;
    }
    
    func next(_ val: Int) -> Double {
        let first = array.removeFirst();
        array.append(val);
        let res: Double = Double(preSum + val) / Double(size);
        preSum -= first;
        preSum += val;
        return res;
    }
    
    var array: [Int];
    var size: Int;
    var preSum: Int = 0;
}
