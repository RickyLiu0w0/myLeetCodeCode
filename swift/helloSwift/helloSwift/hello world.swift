class NameShape {
    var numberOfSides: Int = 0;
    var name: String

    init(name: String) {
        self.name = name;
    }

    func simpleDescription() -> String {
        return "A shape with \(numberOfSides) sides"
    }
}

class Square: NameShape {
    var sideLength: Double

    init(sideLength: Double, name: String) {
        self.sideLength = sideLength
        super.init(name: name)
        numberOfSides = 4
    }

    func area() -> Double {
        return sideLength * sideLength
    }

    override func simpleDescription() -> String{
        return  "A square with sides of length \(sideLength)."
    }
}

class MyCalendar {

    init() {

    }
    
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
            schedule.insert([start, end], at: 0);
            return true
        } else if (start >= schedule[r][1]) {
            schedule.append([start, end]);
            return true;
        }
        
        while (l < r) {
            mid = (r - l) / 2 + l;
            if (start > schedule[mid][0]) {
                if (l == mid) {
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
        
        // l 就是最靠近start且小于start的值（索引）
        if (schedule[l][1] > start){
            return false;
        }
        
        // start合法性验证通过，接下来验证end，l可以保持不动
        if ((schedule[l + 1][0] < end)) {
            return false;
        } else {
            schedule.insert([start, end], at: l + 1);
            return true;
        }
    }

    var schedule: [[Int]] = [];
}
