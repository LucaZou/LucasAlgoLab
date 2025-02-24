#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
    public:
        void removeExtraSpace(string &s){
            int slow = 0;
            for (int fast = 0; fast < s.size(); fast++) {
                if (s[fast] != ' ') {//检测非空格即单词的开始
                    if(slow != 0){//如果不是第一个单词
                        s[slow++] = ' ';//在单词前加一个空格（为了去重前后空格）
                    }
                    while (fast < s.size() && s[fast] != ' ') {//删除多余的空格
                        s[slow++] = s[fast++];
                    } 
                }
            }
            s.resize(slow);
        }
        string reverseWords(string s) {
            //移除多余的空格
            removeExtraSpace(s);
            reverse(s.begin(),s.end());
            int start = 0;
            for (int i = 0; i <= s.size(); i++) {
                if (s[i] == ' ' || i == s.size()) {
                    reverse(s.begin() + start,s.begin() + i);
                    start = i + 1;
                }
            }
            return s;
        }
    };

int main(){
    Solution s;
    string str = "  the sky is blue  ";
    cout << s.reverseWords(str) << endl;
    return 0;
}