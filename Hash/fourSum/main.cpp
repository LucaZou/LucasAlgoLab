#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
    public:
        // int getSum(int a,int b,int c,int d){
        //     return (a+b+c+d);
        // }
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            sort(nums.begin(),nums.end());
            for (int i = 0; i < nums.size(); i++) {
                //去重
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                for (int j = i+1; j < nums.size(); j++) {
                    int left = j+1;
                    int right = nums.size() -1;
                    //去重
                    if (j > i+1 && nums[j] == nums[j - 1]) {
                        continue;
                    }
                    while (left < right) {
                        long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
                        // int sum = getSum(nums[i],nums[j],nums[left],nums[right]);
                        if (sum < target) {
                            left++;
                        }else if(sum > target){
                            right--;
                        }else if(sum == target){
                            result.push_back(vector<int>{nums[i],nums[j], nums[left], nums[right]});
                            //去重
                            while (left < right && nums[left] == nums[left + 1]) left++;
                            while (left < right && nums[right] == nums[right - 1]) right--;
                            left++;
                            right--;
                        }
                        }

                    }
                }
                return result;
            }

        };

int main(){
    //test case
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums,target);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}