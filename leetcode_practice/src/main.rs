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

fn main() {
    println!("Hello, world!");
    let mut os = OrderedStream::new(5);
    println!("{:?}", os.insert(5, "ccccc".to_string())); // 插入 (3, "ccccc")，返回 []
    println!("{:?}", os.insert(1, "aaaaa".to_string())); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
    println!("{:?}", os.insert(2, "bbbbb".to_string())); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
    println!("{:?}", os.insert(3, "eeeee".to_string())); // 插入 (5, "eeeee")，返回 []
    println!("{:?}", os.insert(4, "ddddd".to_string())); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
}
