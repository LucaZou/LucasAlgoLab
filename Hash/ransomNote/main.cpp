#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char,int> map;//保存ransomNote中{每种字符：个数}
            for(char c:ransomNote){
                map[c]++;
            }
            for(char d:magazine){
                if(map.find(d) != map.end() && map[d] >0){
                    map[d]--;
                }
            }
            for(const auto& p:map){
                if(p.second > 0){
                    return false;
                }
            }
            return true;
        }
    };

int main(){
    string ransomNote = "aa";
    string magazine = "aab";
    Solution s;
    cout<<s.canConstruct(ransomNote,magazine)<<endl;
    return 0;
}