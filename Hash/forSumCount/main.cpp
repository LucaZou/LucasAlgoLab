#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            unordered_map<int,int> map1;
            int count =0;
            for(int a:nums1){
                for(int b:nums2){
                    map1[a+b] ++;//将数组1和2中元素相加的值作为键，相同值次数为值
                }
            }
            for(int c:nums3){
                for(int d:nums4){
                    auto t = map1.find(0-(c+d));
                    if(map1.end() != t){
                        count += t->second;
                    }
                }
            }
            return count;
        }
    };

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    Solution s;
    cout<<s.fourSumCount(nums1,nums2,nums3,nums4)<<endl;
    return 0;
}