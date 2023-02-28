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
