#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int getSum(int a,int b,int c){
            return (a+b+c);
        }
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(),nums.end());
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) {
                    return result;
                }
                int left = i+1;
                int right = nums.size() -1;
                //去重
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                while (left < right) {
                    
                    int sum = getSum(nums[i],nums[left],nums[right]);
                    if(sum == 0){
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        while (left < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        left++;
                        right--;
                    }
                    else if (sum < 0) {
                        left++;
                    }
                    else if (sum > 0) {
                        right--;
                    }
                }
            }
            return result;
            
        }
    };

int main(){
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s.threeSum(nums);
    
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}