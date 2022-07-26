class Solution {
    func repeatedCharacter(_ s: String) -> Character {
        // 方法一，0 ms，13.9MB
        // var flagArray: [Bool] = Array(repeating: false, count: 26);
        // let character: [UInt8] = Array(s.utf8);
        // for char in character {
        //     if flagArray[Int(char) - 97] {
        //         return Character(UnicodeScalar(char));
        //     } else {
        //         flagArray[Int(char) - 97] = true;
        //     }
        // }

        // 方法二
        var charSet: Set<Character> = Set<Character>();
        for char in s {
            if charSet.contains(char) {
                return char;
            } else {
                charSet.insert(char);
            }
        }

        return "a";
    }
}