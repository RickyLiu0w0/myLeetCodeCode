## 滑动窗口

```cpp
/* 滑动窗口算法框架 */
void slidingWindow(string s) {
    unordered_map<char, int> window;
    
    int left = 0, right = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 增大窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        // 注意在最终的解法代码中不要 print
        // 因为 IO 操作很耗时，可能导致超时
        printf("window: [%d, %d)\n", left, right);
        /********************/
        
        // 判断左侧窗口是否要收缩，窗口需要缩短的情况
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 缩小窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```

### [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/)

1、什么时候应该移动 right 扩大窗口？窗口加入字符时，应该更新哪些数据？

2、什么时候窗口应该暂停扩大，开始移动 left 缩小窗口？从窗口移出字符时，应该更新哪些数据？

3、我们要的结果应该在扩大窗口时还是缩小窗口时进行更新？

如果一个字符进入窗口，应该增加 window 计数器；如果一个字符将移出窗口的时候，应该减少 window 计数器；当 valid 满足 need 时应该收缩窗口；应该在收缩窗口的时候更新最终结果。

下面是完整代码：

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, target;
        for (auto &c : t) {
            target[c]++;
        }

        int left = 0, right = 0, len = INT_MAX, val = 0, res_left;
        size_t n = s.length();

        while (right < n) {
            char c = s[right++];

            if (target.count(c)) {
                // 是目标
                window[c]++;

                if (target[c] == window[c]) {
                    // 完成匹配
                    ++val;
                }
            }
            while (val == target.size()) {
                // 齐了
                if (right - left < len) {
                    res_left = left;
                    len = right - left;
                }
                char c2 = s[left++];
                if (target.count(c2)) {
                    if (window[c2] == target[c2]){
                        --val;
                    }
                    window[c2]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(res_left, len);
    }
};
```

### [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-character)

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.length();
        int left = 0, right = 0, res = 0;
        map<char, int> window;
        while (right < n)   {
            char c = s[right++];
            window[c]++;
            while (window[c] != 1) {
                // 如果有重复，就要缩小窗口
                window[s[left++]]--;
            }
            res = std::max(res, right - left);
        }
        return res;
    }
};
```
## 回溯（全排列）

```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

### [78. 子集](https://leetcode.cn/problems/subsets/)

1. 画出递归树，找到状态变量(回溯函数的参数)，这一步非常重要※
2. 根据题意，确立结束条件
3. 找准选择列表(与函数参数相关),与第一步紧密关联※
4. 判断是否需要剪枝
5. 作出选择，递归调用，进入下一层
6. 撤销选择

#### 递归树

![子集问题递归树](https://pic.leetcode-cn.com/d8e07f0c876d9175df9f679fcb92505d20a81f09b1cb559afc59a20044cc3e8c-子集问题递归树.png)

观察上图可得，选择列表里的数，都是选择路径(红色框)后面的数，比如`1`这条路径，他后面的选择列表只有 `2、3`，`2` 这条路径后面只有`3`这个选择，那么这个时候，就应该 使用一个参数 start，来标识当前的选择列表的起始位置。也就是标识每一层的状态，因此被形象的称为`状态变量`，最终函数签名如下

```cpp
//nums为题目中的给的数组
//path为路径结果，要把每一条 path 加入结果集
void backtrack(vector<int>nums,vector<int>&path,int start);
```

#### 找结束条件

此题非常特殊，所有路径都应该加入结果集，所以不存在结束条件。或者说当 start 参数越过数组边界的时候，程序就自己跳过下一层递归了，因此不需要手写结束条件,直接加入结果集

```cpp
res.push_back(path);//把每一条路径加入结果集
```

#### 找选择列表

```cpp
for(int i=start;i<nums.size();i++)
```

#### 剪枝

不需要

#### 做出选择(即for 循环里面的)

```cpp
void backtrack(vector<int>nums,vector<int>&path,int start) {
    for(int i=start;i<nums.size();i++) {
        path.push_back(nums[i]);//做出选择
        backtrack(nums,path,i+1);//递归进入下一层，注意i+1，标识下一个选择列表的开始位置，最重要的一步
    }
}
```
#### 撤销选择

```cpp
void backtrack(vector<int>nums,vector<int>&path,int start) {
    res.push_back(path);
    for(int i=start;i<nums.size();i++) {
        path.push_back(nums[i]);//做出选择
        backtrack(nums,path,i+1);//递归进入下一层，注意i+1，标识下一个选择列表的开始位置，最重要的一步
        path.pop_back();//撤销选择
    }
}
```

代码：

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, path, 0);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& path, size_t start) {
        size_t n = nums.size();
        res.emplace_back(path);
        for (size_t i = start; i < n; ++i) {
            path.emplace_back(nums.at(i));  // 做出选择
            backtrack(nums, path, i + 1);  // 递归进入下一层，注意i+1，标识下一个选择列表的开始位置，最重要的一步
            path.pop_back();  // 撤销选择
        }
        return;
    }
};
```

### [46. 全排列](https://leetcode.cn/problems/permutations/)

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return res;
    }

private:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& track) {
        size_t n = nums.size();

        // 结束条件
        if (track.size() == n) {
            res.emplace_back(track);
            return;
        }

        for (size_t i = 0; i < n; ++i) {
            if (find(track.begin(), track.end(), nums.at(i)) != track.end()) {
                continue;
            }
            track.emplace_back(nums.at(i));
            backtrack(nums, track);
            track.pop_back();
        }
        return;
    }
};
```

