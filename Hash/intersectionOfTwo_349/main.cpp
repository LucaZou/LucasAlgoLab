#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> result;
            unordered_set<int> nums_set(nums1.begin(),nums1.end());
            for(int num : nums2){
                if(nums_set.find(num) != nums_set.end()){
                    result.insert(num);
                }
        
            }
            return vector<int>(result.begin(),result.end());
        }
    };

int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution s;
    vector<int> result = s.intersection(nums1,nums2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}