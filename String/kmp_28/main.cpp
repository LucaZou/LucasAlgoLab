#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        vector<int> getNext(string s) {
            int len = s.size();
            vector<int> next(len, 0);  // 直接初始化长度为len的数组
            int prefix_len = 0;        // 当前最长公共前后缀长度
            int i = 1;
        
            while (i < len) {
                if (s[prefix_len] == s[i]) {
                    prefix_len++;
                    next[i] = prefix_len;
                    i++;
                } else {
                    if (prefix_len == 0) {
                        next[i] = 0;
                        i++;  // 别忘了移动i
                    } else {
                        prefix_len = next[prefix_len - 1];  // 回退，继续比较
                    }
                }
            }
            return next;
        }

        int strStr(string haystack, string needle) {
            if (needle.size() == 0) {
                return 0;
            }
            
            vector<int> next = getNext(needle);
            int j = 0;
            
            for (int i = 0; i < haystack.size(); i++) {
                while (j > 0 && haystack[i] != needle[j]) {
                    j = next[j - 1];  // 回退 needle 的指针
                }
                if (haystack[i] == needle[j]) {
                    j++;  // 匹配成功，needle 指针前进
                }
                if (j == needle.size()) {
                    return i - j + 1;  // 找到完整匹配，返回起始位置
                }
            }
            return -1;  // 未找到匹配
        }
    };

int main(){
    Solution s;
    string haystack = "aabaabaafa";
    string needle = "aabaaf";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}