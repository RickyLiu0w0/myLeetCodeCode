[toc]

## 滑动窗口

[同向双指针 滑动窗口【基础算法精讲 01】](https://www.bilibili.com/video/BV1hd4y1r7Gq)

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

### [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

直接滑动窗口，找到大于`target`的时候就缩小窗口

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = 0;
        int sum = 0, res = INT_MAX;
        while (r < n) {
            // 窗口往右扩展
            sum += nums[r++];

            while (l < r && sum >= target) {
                // 达到目标
                res = min(res, r - l);

                // 缩小窗口
                sum -= nums[l++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

### [713. 乘积小于 K 的子数组](https://leetcode.cn/problems/subarray-product-less-than-k/)

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        size_t size = nums.size(), left = 0, right = 0;
        long long  mul = 1;
        int res = 0;
        while (right < size) {
            mul *= nums[right++];
            while (left < right && mul >= k) {
                mul /= nums[left++];
            }
            // 说明[l, r), [l + 1, r), ..., [r - 1, r)都是符合的
            // 个数为 r - 1 - l + 1 == r - l;
            res += right - left;
        }
        return res;
    }
};
```
### [1574. 删除最短的子数组使剩余数组有序](https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)

```cpp
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // 从右面开始找右边的严格递增，保证右边严格递增
        int size = arr.size();
        int r = size - 1;
        while (r > 0 && arr[r - 1] <= arr[r]) {
            --r;
        }

        if (!r) {
            return 0;
        }

        // 找到右边的最低点arr[r]，然后找左边的递增序列，保持和右递增序列衔接
        // 如何保持衔接？r++ 直到 arr[l] <= arr[r]
        int l = 0, res = r;
        while (l == 0 || arr[l - 1] <= arr[l]) {
            while (r < size && arr[l] > arr[r]) {
                r++;
            }
            res = min(res, r - l - 1);
            ++l;
        }
        return res;
    }
};
```

思考题（变形题）

!!! question 问：至少修改多少个数，使得修改后的数组是非递减的？（等价于删除一个最短的子序列）

答：先计算最长非递减子序列，再用`n`减去这个子序列的长度，就得到了删除子序列的最短长度。具体见[【基础算法精讲 20】](https://www.bilibili.com/video/BV1ub411Q7sB)。题目中的是最长递增子序列，要改为最长非递减子序列，则需要将代码中的`lower_bound`改为`upper_bound`。

!!! question 问：至少修改多少个数，使得修改后的数组是严格递增的？

答：严格递增等价于对于任意$i>j$，有
$$arr[i]−arr[j] \geq i−j$$
变形得
$$arr[i]−i \geq arr[j]−j$$

也就转化为**最长非递减子序列**。

故构造$b[i]=arr[i]−i$
求`b`的最长非递减子序列，再用`n`减去这个子序列的长度，就得到了答案。

### [1040. 移动石子直到连续 II](https://leetcode.cn/problems/moving-stones-until-consecutive-ii/)

![【图解】下跳棋（Python/Java/C++/Go）](https://pic.leetcode.cn/1680696212-AUVzBz-1040-cut.png)

```cpp
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        vector<int>& s = stones;
        sort(s.begin(), s.end());

        int n = s.size();
        // 把前面的往后挪
        // 在(1, n-1)中，应该有s[n-1] - s[1] - 1个数，现在已存在(n - 3)个数
        // 空位数量（需补充，还差） s[n-1] - s[1] - 1 - (n - 3) 个数
        int res1 = s[n - 1] - s[1] + 2 - n;

        // 把后面的往前挪
        // 空位数量 s[n-2] - s[0] - 1 - (n - 3)
        int res2 = s[n - 2] - s[0] + 2 - n;
        int max_res = max(res1, res2);

        if (!res1 || !res2) {
            // 有一边是排紧凑了
            return {min(2, max_res), max_res};
        }

        int min_res = 0, left = 0, right = 0;

        while (right < n) {
            // 这个双指针是寻找数字的最大窗口
            // 窗口内部一定满足s[right] - s[left] + 1 <= n
            while (s[right] - s[left] + 1 > n) {
                ++left;
            }
            min_res = max(min_res, right - left + 1);
            ++right;
        }
        return {n - min_res, max_res};
    }
};
```

### [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/)

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;

        for (auto& c: t) {
            map[c]++;
        }

        int l = 0, r = 0, begin = 0, sub_size = INT_MAX, target_num = map.size(), n = s.length();

        while (r < n) {
            char c = s[r++];

            if (map.count(c)) {
                map[c]--;

                if (map[c] == 0) {
                    // 已经完成
                    target_num--;
                }

                while (target_num == 0) {
                    if (sub_size > r - l) {

                        begin = l;
                        sub_size = r - l;
                    }

                    char cc = s[l++];

                    if (map.count(cc)) {
                        map[cc]++;
                        if (map[cc] == 1) {
                            target_num++;
                        }
                    }
                }
            }
        }

        return sub_size == INT_MAX ? "" : s.substr(begin, sub_size);
    }
};
```

## 回溯（全排列）

### 问题集

1. [112. 路径总和](https://leetcode.cn/problems/path-sum)
2. [113. 路径总和 II](https://leetcode.cn/problems/path-sum-ii)
3. [131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning)
4. [140. 单词拆分 II](https://leetcode.cn/problems/word-break-ii)

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

观察上图可得，选择列表里的数，都是选择路径(红色框)后面的数，比如`1`这条路径，他后面的选择列表只有 `2、3`，`2` 这条路径后面只有`3`这个选择，那么这个时候，就应该 使用一个参数`start`，来标识当前的选择列表的起始位置。也就是标识每一层的状态，因此被形象的称为`状态变量`，最终函数签名如下

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
### [剑指 Offer 38. 字符串的排列](https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/)

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        string path;
        vector<string> res;
        backTrack(path, s, 0);
        res.assign(se.begin(), se.end());
        return res;
    }
private:
    set<string> se;
    void backTrack(string &path, string& s, uint16_t set) {
        int n = s.length();
        if (path.length() == n) {
            se.insert(path);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (set & (1 << j)) {
                // 该位置的字符已经放过
                ;
            } else {
                path.push_back(s[j]);
                backTrack(path, s, set | (1 << j) );
                path.pop_back();
            }
        }
    }
};
```

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        backtrack(s, 0);
        return res;
    }
private:
    vector<string> res;
    void backtrack(string& s, size_t begin) {
        size_t n = s.length();
        if (begin == n) {
            res.emplace_back(s);
            return;
        }

        set<char> se;
        for (size_t i = begin; i < n; ++i) {
            if (se.count(s[i]) != 0) continue; // 该字母已存在过这个位置
            // 将处于i的字母固定在当前位置
            se.insert(s[i]);
            swap(s, i ,begin);
            backtrack(s, begin + 1);
            swap(s, i , begin); // 撤销选择
        }
    }

    inline void swap(string& s, size_t i, size_t j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
};
```

### [130. 被围绕的区域](https://leetcode.cn/problems/surrounded-regions/)

回溯，将和边界相连的`O`转变为`%`，然后将剩下的`O`转为`X`，`%`变回`O`。

![示例1](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board.front().size();
        const array<array<int, 2>, 4> direction = {0,-1, 0, 1, -1, 0, 1,0};
        function<void(int, int)> dfs = [&](int row, int col) {
            if (row == -1 || col == -1 || row == m || col == n || 'O' != board[row][col]) {
                // 结束条件
                return;
            }

            // 作出处理
            board[row][col] = '%'; // 特殊标记
            
            // 选择列表
            for (int i = 0; i < 4; ++i){
                // 遍历上下左右四个方向
                dfs(row + direction[i][0], col + direction[i][1]);
            }
            return;
        };

        // 将与边边相连的O都更改标记为%
        for (int j = 0; j < n; ++j) {
            // 第一行以及最后一行
            dfs(0, j);
            dfs(m - 1, j);
        }

        for (int i = 1; i < m - 1; ++i) {
            // 第一列以及最后一列，排除第一行以及最后一行，因为已经处理了
            dfs(i, 0);
            dfs(i, n - 1);
        }

        // 将中间内部的O转变为X，%转为O
        for (auto& r : board) {
            for (auto& item : r) {
                if (item == 'O') {
                    item = 'X';
                } else if (item == '%') {
                    item = 'O';
                }
            }
        }
        return;
    }
};
```

### [93. 复原 IP 地址](https://leetcode.cn/problems/restore-ip-addresses/)

难点在不能有前导0

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();

        if (n < 4 || n > 16) {
            return {};
        }
        vector<string> res;
        // begin起始下标，block_index，第几块
        function<void(int begin, int block_index)> dfs = [&](int begin, int block_index) {
            // 结束条件
            if (s.size() <= begin) {
                return;
            }

            if (block_index == 3) {
                // 最后一块
                if (s.size() - begin > 3) {
                    // 最后一块长度大于3，不合法分割，或者啥东西都不剩了
                    return;
                }

                if (stoi(s.substr(begin)) <= 255) {
                    if (s.size() - begin > 1 && s[begin] == '0') {
                        // 出现前导0
                        return;
                    }

                    // cout << "1: " << s.substr(begin) << endl;
                    // xxx.xxx.xxx.0 ~ xxx.xxx.xxx.255
                    // cout << "res " << s << endl;
                    res.emplace_back(s);
                }
                return;
            }

            // 选择列表，当前block内可以选0～255，但是不能前导0

            // 一个位 .0. ~ .9.
            // 确保.之后的不是0
            // cout << "2: " << s[begin] << endl;
            s.insert(begin + 1, ".");
            dfs(begin + 2, block_index + 1);
            s.erase(begin + 1, 1);  // 撤销选择

            // 两个到三个位 .10. ~ .255.
            // 不能有前导0
            if (s[begin] != '0') {
                for (int i = 2; i <= 3 && begin + i < s.size(); ++i) {
                    // 确保不大于255
                    // cout << "2: " << s.substr(begin, i) << endl;
                    if (stoi(s.substr(begin, i)) > 255) {
                        continue;
                    }
                    
                    s.insert(begin + i, ".");
                    dfs(begin + 1 + i, block_index + 1);
                    s.erase(begin + i, 1);  // 撤销选择
                }
            }

            return;
        };
        dfs(0, 0);
        return res;
    }
};
```

## 动规相关

### [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

> 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
> 
> 子数组 是数组中的一个连续部分。

由于是连续，所以**选与不选**的点在：
1. 加入前面的队列
2. 自己新开一个队列

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp_old = -10000, dp_new;
        int res = INT_MIN;
        for (auto& num : nums) {
            dp_new = max(dp_old + num, num);
            res = max(res, dp_new);
            dp_old = dp_new;
        }
        return res;
    }
};
```

### [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

!!! note 思路

[最长递增子序列](https://www.bilibili.com/video/BV1ub411Q7sB)

```cpp
int lengthOfLIS(vector<int>& nums) {
        // g[i] 表示长度i+1的LTS的末尾元素最小值
        /**
         * nums = [1,6,7,2,4,5,3]
         * g = [0,0,0,0,0,0,0]
         * g = [1,0,0,0,0,0,0] 1
         * g = [1,6,0,0,0,0,0] 6
         * g = [1,6,7,0,0,0,0] 7
         * g = [1,2,7,0,0,0,0] 2
         * g = [1,2,4,0,0,0,0] 4
         * g = [1,2,4,5,0,0,0] 5
         * g = [1,2,3,5,0,0,0] 3
         *
         */

        int ng = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto pos = lower_bound(nums.begin(), nums.begin() + ng, nums[i]);
            if (pos == ng + nums.begin()) {
                // 找不到，直接加入末尾
                nums[ng] = nums[i];
                ng++;
            } else {
                // 找到，换成最小值
                *pos = nums[i];
            }
        }
        return ng;
}
```

### [1626.无矛盾的最佳球队](https://leetcode.cn/problems/best-team-with-no-conflicts/)

```cpp
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> vp;
        size_t n = scores.size();
        for (size_t i = 0; i < n; ++i) {
            vp.emplace_back(make_pair(scores.at(i), ages.at(i)));
        }

        sort(vp.begin(), vp.end(), [](pair<int, int>& x, pair<int, int>& y) -> bool {
            // 分数优先，年龄随后
            if (x.first < y.first) {
                return true;
            } else if (x.first > y.first) {
                return false;
            } else {
                return x.second < y.second;
            }
        });

        vector<int> dp(n, 0);

        int res = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (vp[j].second <= vp[i].second) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += vp[i].first;
            res = max(res, dp[i]);
        }

        return res;
    }
};
```

### [343. 整数拆分](https://leetcode.cn/problems/integer-break/)

这题就是用动归做

一个数nn，要将其拆分成为`(i, nn - i)`，`i`从`[1, nn)`中取，然后再判断需不需要拆分

`nn - i`为不拆分，`dp(nn - i)`为继续拆分

```cpp
class Soluction {
public:
    int integerBreak(int n) {
        vector<int> memo(59, -1);
        memo[0] = 0;
        memo[1] = 1;
        function<int(int)> dp = [&](int nn) -> int {
            if (memo[nn] != -1) {
                return memo[nn];
            }

            int res = INT_MIN;
            for (int i = 1; i < nn; i++) {
                res = max(res, i * max(nn - i, dp(nn - i)));
            }
            memo[nn] = res;
            return res;
        };
        return dp(n);
    }
};
```

### [10. 正则表达式匹配](https://leetcode.cn/problems/regular-expression-matching/)

!!! note 思路

[经典动态规划：正则表达式](https://labuladong.github.io/algo/di-er-zhan-a01c6/yong-dong--63ceb/jing-dian--8d516/)


```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        return dp(s, 0, p, 0);
    }

private:
    unordered_map<string, bool> memo;  // 备忘录

    // s[..i]和p[..j]是否匹配
    bool dp(string& s, int i, string& p, int j) {
        // base case
        int m = s.length(), n = p.length();
        if (j == n) {
            // 模式指针已走到末尾，现在只需判断字符串指针i是否已到末尾
            return m == i;
        }

        if (m == i) {
            // 字符串指针i已到末尾
            // 剩下的模式可能有三种情况
            // A*B (false)
            // A*B* (true)
            // A*BB (false)
            if ((n - j) % 2) {
                // A*B
                return false;
            }
            for (; j < n; j += 2) {
                if (p[j + 1] != '*') {
                    // A*BB (false)
                    return false;
                }
            }

            return true;  // A*B* (true)
        }
        /*------------ base case end -------------------*/
        string key = to_string(i) + "," + to_string(j);
        bool res = false;
        if (memo.count(key) != 0) return memo[key];
        if (s[i] == p[j] || p[j] == '.') {
            // 匹配上了
            if (j < n - 1 && p[j + 1] == '*') {
                // 这是一个通配符，但是不确定有没有用上
                res =  /* 没用上 */ dp(s, i, p, j + 2) || /* 用上了，通过递归才直到用了多少次 */ dp(s, i + 1, p, j);
            } else {
                // 老老实实一个一个匹配
                res =  dp(s, i + 1, p, j + 1);
            }
        } else {
            // 匹配不上
            if (j < n - 1 && p[j + 1] == '*') {
                // 这是一个通配符（免死金牌），但0次匹配，j直接到下一个
                res = dp(s, i, p, j + 2);
            } else {
                // 没有免死金牌，无了
                res = false;
            }
        }
        memo[key] = res;
        return res;
    }
};
```
### [1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int one = text1.length();
        int two = text2.length();

        vector<vector<int>> dp(one + 1, vector<int>(two + 1, 0));

        for (int i = 1; i <= one; ++i) {
            for (int j = 1; j <= two; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[one][two];
    }
};
```

### [1035. 不相交的线](https://leetcode.cn/problems/uncrossed-lines/)

相等的情况下，同时选择

不相等的情况下，选择最小的一个

```c++
class Solution {
    // 题目就是最长公共子序列
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        /**
         * dp[i][j]代表num1的[0, i]以及num2[0, j]的最长公共子序列
         *               _
         *              | dp[i-1][j-1] + 1  (nums1[i] == nums2[j])
         * dp[i][j] == <
         *              | max(dp[i-1][j], dp[i][j-1])) (nums1[i] != nums2[j])
         *               _
         */

        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // for (auto& v : dp) {
        //     for (auto& num : v) {
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m][n];
    }
};
```

## 区间DP

### [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/)

[区间 DP：最长回文子序列 最优三角剖分【基础算法精讲 22】](https://www.bilibili.com/video/BV1Gs4y1E7EU)

由首尾判断是否相等，相等则选入，+2；不相等则选择其中一个

由于`dp[i][j]`要由`i+1`和`j-1`得出，所以i要倒叙遍历，j要正序遍历

一个字符`dp[i][i]`情况下，回文长度为1

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j]代表从i到j的长回文子序列
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i > -1; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    // 两个都要选
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // 选其中一个
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
```

### [1039. 多边形三角剖分的最低得分](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/)

![多边形三角剖分的最低得分](https://pic.leetcode.cn/1680388698-XNaKai-1039-cut.png)

```cpp
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // 计算从i到j的字问题
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (j == i + 1) {
                // 没有三角形
                return 0;
            }
            if (dp[i][j] != -1) return dp[i][j];

            int res = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                // 枚举(i,k)多边形，(k,j)多边形，以及[i,j,k]三角形
                res = min(res, values[i] * values[j] * values[k] + dfs(i, k) + dfs(k, j));
            }
            dp[i][j] = res;
            return res;
        };

        return dfs(0, n - 1);
    }
};
```

## 数位DP

### [2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers/)

!!! note 思路

[数位 DP 通用模板](https://www.bilibili.com/video/BV1rS4y1s721)

```cpp
class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int memo[s.size()][1 << 10];
        memset(memo, -1, sizeof(memo));  // -1 表示没有计算过
        
        // 返回从第i位开始填数字，已填集合为mask，能够构造出至少一位重复数字的个数
        // is_limit，检查前面的数字是否都是n对应位上的，如果为 true 则第i位只能填s[i]，否则可以最高填9
        // is_num，检查前面是否以前填过数字，ture则前面填过，第i位可以填0-9；如果为 false，我们可以跳过，或者第i位置只能填1-x，x由is_limit约束

        function<int(int, bool, bool, uint16_t)> f = [&](int i, bool is_limit, bool is_num, uint16_t mask) -> int {
            if (i == s.length()) {
                return is_num;  //  前面填了的话，这是一个可行结果
            }

            int res = 0;
            if (!is_num) {
                // 不选，直接跳到下一个
                res = f(i + 1, false, false, mask);
            }

            // 选
            int up = is_limit ? (s[i] - '0') : 9;
            for (int j = 1 - is_num; j <= up; ++j) {
                if ((mask & (1 << j)) == 0) {
                    // 没有填过
                    res += f(i + 1, is_limit && (j == s[i] - '0'), true, mask | (1 << j));
                }
            }
            
            if (!is_limit && is_num)
                memo[i][mask] = res;

            return res;
        };

        return f(0, true, false, 0);
    }
};
```

### [1012. 至少有 1 位重复的数字](https://leetcode.cn/problems/numbers-with-repeated-digits/)

[2376题](#2376.统计特殊整数)的补集

```cpp
return n - f(0, true, false, 0);
```

## 数学

### [剑指 Offer 14- II. 剪绳子 II](https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/)

可以证明每三段三段分割出来最好的

但是4的分割是`(2, 2)`而不是`(1,3)`

```cpp
const int MOD = 1000000007;
class Solution {
public:
    int cuttingRope(int n) {
        // 直接除3
        // 基本判断
        if (n < 3) return 1;
        if (n == 3) return 2;

        uint32_t res = 1;
        while (n > 4) {
        /**
         * 最后剩下4，就分为 2 * 2
         * 最后剩下3，就直接乘上3，不拆分
         * 最后剩下2，就乘上2，也不拆分
         * 最后剩下1，就乘上1，也不拆分
         */
            res *= 3;
            res %= MOD;
            n -= 3;
        }

        return (n * res) % MOD;
    }
};
```

### [1017. 负二进制转换(十进制转其他进制)](https://leetcode.cn/problems/convert-to-base-2/)

模版

```cpp
auto f = [](int n, int K) -> vector<int> {
    vector<int> res;
    while (n) {
        int r = (n % K + abs(K)) % abs(K);
        n -= r;
        n /= K;
        res.emplace_back(r);
    }
    reverse(res.begin(), res.end());
    return res;
};

```

本题代码

```cpp
class Solution {
public:
    string baseNeg2(int n) {
        auto f = [](int n, int K) -> vector<int> {
            vector<int> res;
            while (n) {
                int r = (n % K + abs(K)) % abs(K);
                n -= r;
                n /= K;
                res.emplace_back(r);
            }
            reverse(res.begin(), res.end());
            return res;
        };
        vector<int> res = f(n, -2);
        string s;
        for (auto x : res) {
            s.push_back(x + '0');
        }
        return s;
    }
};
```

## 链表

[反转链表【基础算法精讲 06】](https://www.bilibili.com/video/BV1sd4y1x7KN)

### [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};
```

### [234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/)

先把前半部分反转，然后再一一比对

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 反转一半链表，然后和后面的比对
        if (!head->next) return true;

        // 获取链表长度
        int n = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            ++n;
        }

        int mid = n >> 1;
        ListNode* pre = nullptr;
        ListNode* cur = head, *nxt;

        for (int _ = 0; _ < mid; ++_) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        // pre就是list1
        // cur就是list2
        if (n % 2) {
            // 长度为奇数，中间不用管
            cur = cur->next;
        }

        while (cur) {
            if (cur->val != pre->val) {
                return false;
            }

            cur = cur->next;
            pre = pre->next;
        }
        return true;
    }
};
```

### [24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

这题要添加哨兵节点，i从1开始算，每次加`k(这里是2)`个，`<n`条件。

```cpp
ListNode* swapPairs(ListNode* head) {
        // 获取链表长度
        int n = 0;
        ListNode* p = head;
        while (p) {
            ++n;
            p = p->next;
        }

        ListNode h(0, head);
        ListNode *cur = head, *pre, *head_ptr = &h;
        for (int i = 1; i < n; i += 2) {
            ListNode* nxt;
            pre = nullptr;
            for (int _ = 0; _ < 2; ++_) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }

            nxt = head_ptr->next;
            head_ptr->next->next = cur;
            head_ptr->next = pre;
            head_ptr = nxt;
        }
        return h.next;
}
```

## 并查集

!!! note 讲解：[并查集（UNION-FIND）算法](https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-03a72/bing-cha-j-323f3/)

### [323. 无向图中连通分量的数目(plus)](https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/description/)

你有一个包含`n`个节点的图。给定一个整数`n`和一个数组`edges`，其中`edges[i] = [ai, bi]`表示图中$a_i$和$b_i$之间有一条边。

返回**图中已连接分量的数目**。

并查集的返回就是联通分量的个数

!!! example 示例 1:

![示例 1:](https://assets.leetcode.com/uploads/2021/03/14/conn1-graph.jpg)

输入: `n = 5`, `edges = [[0, 1], [1, 2], [3, 4]]`
输出: `2`

!!! example 示例 2:


![示例 2:](https://assets.leetcode.com/uploads/2021/03/14/conn2-graph.jpg)

输入: `n = 5`, `edges = [[0,1], [1,2], [2,3], [3,4]]`
输出: `1`

```cpp
class UF{
public:
    explicit UF(int n):count(n), parent(n) {
        int i = 0;
        for (auto& x: parent) {
            x = i++;
        }
    }

    int get_count() const {
        return count;
    }

    int find(int x) {
        if (x != parent[x]) {
            // 不是根节点
            // 找到根节点之后将当前节点x的父节点都设置为根节点
            parent[x] = find(parent[x]);
        }

        // 返回根节点
        return parent[x];
    }

    void connect(int p, int q) {
        int root_p = find(p);
        int root_q = find(q);
        if (root_p == root_q) {
            // 它们是同一根节点，说明在同一颗树上，无需拼接
            return;
        }
        
        // 任意将根节点拼接
        parent[root_p] = root_q; // 这是将p拼在q的子树上
        // parent[root_q] = root_p; // 这个也行
        count--; // 少了一个联通分量
        return;
    }
private:
    vector<int> parent;
    int count;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UF uf(n);
        for (auto& pair : edges) {
            // 连接两个点
            uf.connect(pair[0], pair[1]);
        }
        return uf.get_count();
    }
};
```

### [990. 等式方程的可满足性](https://leetcode.cn/problems/satisfiability-of-equality-equations/)

```cpp
class UF {
public:
    explicit UF(int n) : parent_(n) {
        int i = 0;
        for (auto& x : parent_) {
            x = i++;
        }
    }

    // 省略...

    bool if_set(int p, int q) { return find(p) == find(q); }

private:
    vector<int> parent_;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);

        for (auto& s : equations) {
            if (s[1] == '=') {
                uf.connect(s[0] - 'a', s[3] - 'a');
            }
        }

        for (auto& s : equations) {
            if (s[1] == '!') {
                if (uf.if_set(s[0] - 'a', s[3] - 'a')) {
                    return false;
                }
            }

        }
        return true;
    }
};
```

## 前缀和

### [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)

假设前缀和数组`s[n+1]`，有和区间`s[j] - s[i]`代表`(i,j]`之间的和。

题意要求和为`k`，即`s[j] - s[i] == k`，变换得`s[j] - k == s[i]`，且`i < j`。

这里不能用`s[i] + k == s[j]`，因为`s[i]`会先被算出来，且在将前缀和`s[j]`加入hash之前就要进行上述判断，严格保证`i < j`。**不能把前缀和全部算完再判断。**

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, res = 0, sum = 0;
        unordered_map<int, int> pre_sum_map;
        pre_sum_map[0] = 1;
        int i = 0;

        // s[j] - s[i] = k
        // s[j] - k = s[i] 要确保 i < j
        for (auto& num : nums) {
            sum += num;
            if (pre_sum_map.count(sum - k)) {
                // 找到s[i]
                res += pre_sum_map[sum - k];
            }
            pre_sum_map[sum]++;
        }
        return res;
    }
}
```


### [525. 连续数组](https://leetcode.cn/problems/contiguous-array/)

!!! tip 转变为和为0的子数组

子数组0和1的个数相等

相当于

将`0 -> -1`，`1 -> 1`，子数组内和为0，用到前缀和

有前缀和数组`S`，当`i < j`，有和区间`s[j] - s[i]`代表`(i,j]`之间的和。

要求和为0，即`s[j] == s[i]`

`j`从`[1,n]`遍历，`s[0] = 0`。当遇到`s[j] == s[i]`时，即`(i,j]`之间是满足题意的子数组，计算`j - i`，即子区间长度。此时保留`s[i]`不用更改下标。若`s[j]`的值在哈西表中不存在，则记录当前下标`j`。

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for (auto & num : nums) {
            num = (num << 1) - 1; // 1 -> 1, 0 -> -1
        }
        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 0;
        int res = 0;
        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            if (hash.count(sum)) {
                // 找到s[i]，令s[j] - s[i] == 0
                res = max(res, j + 1 - hash[sum]);
            } else {
                hash[sum] = j + 1;
            }
        }
        return res;
    }
};
```

## 单调栈

### [1019. 链表中的下一个更大节点](https://leetcode.cn/problems/next-greater-node-in-linked-list/)

![用每个数，更新其它数的下一个更大元素](https://pic.leetcode.cn/1681051452-kjwDTN-1019-2-c.png)

```cpp
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> st;
        int index = 0;
        vector<int> res;

        while (head) {
            int val = head->val;

            while (!st.empty() && val > st.top().first) {
                res[st.top().second] = val;
                st.pop();
            }

            st.push(make_pair(val, index));
            res.emplace_back(0);
            head = head->next;
            ++index;
        }
        return res;
    }
};
```

其实可以用`res/ant`数组记录数字，`st`栈只记录下标`res/ant`数组中的下标

```cpp
class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> ans;
        stack<int> st; // 单调栈（只存下标）
        for (auto cur = head; cur; cur = cur->next) {
            while (!st.empty() && ans[st.top()] < cur->val) {
                ans[st.top()] = cur->val; // ans[st.top()] 后面不会再访问到了
                st.pop();
            }
            st.push(ans.size()); // 当前 ans 的长度就是当前节点的下标
            ans.push_back(cur->val);
        }
        while (!st.empty()) {
            ans[st.top()] = 0; // 没有下一个更大元素
            st.pop();
        }
        return ans;
    }
};
