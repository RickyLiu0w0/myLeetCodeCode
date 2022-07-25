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
    func distanceBetweenBusStops(_ distance: [Int], _ start: Int, _ destination: Int) -> Int {
        var total: Int = 0;
        var subDistance: Int = 0;
        for (index, value) in distance.enumerated() {
            if index >= start && index < destination {
                subDistance += value;
            }
            
            total += value;
        }
        
        return (subDistance < total - subDistance) ? subDistance : total - subDistance;
    }
}
