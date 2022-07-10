/*
 * @lc app=leetcode.cn id=676 lang=swift
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
/*
    Accepted 2022-07-11
    83/83 (188 ms)
    Your runtime beats 100 % of swift submissions
    Your memory usage beats 100 % of swift submissions (14.6 MB)
*/
class MagicDictionary {

    init() {}
    
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

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * let obj = MagicDictionary()
 * obj.buildDict(dictionary)
 * let ret_2: Bool = obj.search(searchWord)
 */
// @lc code=end

