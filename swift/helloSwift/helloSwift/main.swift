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

class MagicDictionary {

    init() {
        
    }
    
    func buildDict(_ dictionary: [String]) {
        self.dictionary_ = Set<String>(dictionary);
    }
    
    func search(_ searchWord: String) -> Bool {
        let stringSize: Int = searchWord.count;
        for item in self.dictionary_ {
            if (item.count != stringSize) {
                continue;
            }
            
            var flag: Bool = true;
            var check: Bool = false;
            
            for index in searchWord.indices {
                if item[index] != searchWord[index] {
                    if flag {
                        flag = false;
                        check = true;
                    } else {
                        check = false;
                        break;
                    }
                }
            }
            
            if check {
                return true;
            }
        }
        return false;
    }
    
    var dictionary_: Set<String> = [];
}