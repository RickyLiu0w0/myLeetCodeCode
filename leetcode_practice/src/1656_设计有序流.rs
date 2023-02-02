/*
 * @lc app=leetcode.cn id=1656 lang=rust
 *
 * [1656] 设计有序流
 */

/*
    Accepted 2023-02-01
    101/101 (24 ms)
    Your runtime beats 100 % of rust submissions
    Your memory usage beats 100 % of rust submissions (2.8 MB)
 */

// @lc code=start
struct OrderedStream {
    ptr: usize,
    stream: Vec<String>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl OrderedStream {
    fn new(n: i32) -> Self {
        Self {
            ptr: 0,
            stream: vec![String::from(""); n as usize],
        }
    }

    fn insert(&mut self, id_key: i32, value: String) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        self.stream[(id_key - 1) as usize] = value;
        if id_key - 1 == self.ptr as i32 {
            while self.ptr != self.stream.len() && "" != &(self.stream)[self.ptr] {
                res.push((self.stream)[self.ptr].clone());
                self.ptr += 1;
            }
        }
        res
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * let obj = OrderedStream::new(n);
 * let ret_1: Vec<String> = obj.insert(idKey, value);
 */
// @lc code=end

/*
["OrderedStream","insert","insert","insert","insert","insert"]\n
[[5],[3,"ccccc"],[1,"aaaaa"],[2,"bbbbb"],[5,"eeeee"],[4,"ddddd"]]\n
["OrderedStream","insert","insert","insert","insert","insert"]\n
[[5],[5,"ccccc"],[4,"aaaaa"],[3,"bbbbb"],[1,"eeeee"],[2,"ddddd"]]\n
 */
