#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            //将nums加入map中，key为nums[i]，value为i
            unordered_map<int,int> map;
            for (int i = 0; i< nums.size(); i++) {
                auto t = map.find(target - nums[i]);
                if(t != map.end()){
                    return {t->second,i};
                }
                map[nums[i]] = i;
            }
            return {};

        }
    };

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;
    Solution s;
    vector<int> res = s.twoSum(nums,target);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}