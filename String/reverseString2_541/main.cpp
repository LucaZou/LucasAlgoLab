#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
    public:
        string reverseStr(string s, int k) {
            for(int i =0;i<s.size();i+=(2*k)){
                if (i+k < s.size()) {
                    reverse(s.begin()+i,s.begin()+i+k);
                }else {
                    reverse(s.begin()+i,s.end());
                }
            }
            return s;
        }
        
    };

int main(){
    Solution s;
    string str = "abcdefg";
    int k = 8;
    cout<<s.reverseStr(str,k)<<endl;
    return 0;
}